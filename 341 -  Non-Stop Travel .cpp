/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define SZ 107

int N , pred[SZ] , d[SZ] ;
bool Vis[SZ];

struct Node{
    int v , w ;
    Node(){}
    Node(int _v , int _w){
        v = _v , w = _w ;
    }
    bool operator <(const Node &a) const{
        if (w != a.w) return (w > a.w);
        return (v > a.v);
    }
};

vector<Node>adj[SZ];

void Reset(){
    rep(i,N+1) {
        adj[i].clear();
        d[i] = pred[i] = -1 ;
        Vis[i] = false ;
    }
}

void Dijstra(int src){
    priority_queue<Node>Q;
    d[src] = 0 ;
    Q.push( Node(src,0) );
    while(!Q.empty()){
        Node now = Q.top(); Q.pop();
        int currNode = now.v , currCost = now.w ;
        if(Vis[currNode])continue;
        Vis[currNode] = true ;
        forstl( it , adj[currNode] ){
            int nxtNode = it->v , nxtCost = it->w ;
            if( currCost + nxtCost < d[nxtNode] || d[nxtNode] == -1 ){
                d[nxtNode] = currCost + nxtCost ;
                Q.push( Node( nxtNode , d[nxtNode] ) );
                pred[nxtNode] = currNode ;
            }
        }
    }
}

void Input(){
    Reset();
    For(u,N){
        int ed = II ;
        rep(i,ed){
            int v = II , w = II ;
            adj[u].pb( Node(v,w) );
            //adj[v].pb( Node(u,w) );
        }
    }
}

void printPath(int u ){
    if(u == -1 )return ;
    printPath( pred[u] );
    printf(" %d",u);
}


int main()
{
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1;
    while( scanf("%d",&N) &&N ){
        Input();
        int src = II , dest = II ;
        Dijstra(src);
        printf("Case %d: Path =",cs++);
        printPath(dest);
        printf("; %d second delay\n",d[dest]);
    }
}
