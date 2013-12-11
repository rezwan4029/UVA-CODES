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

int e[25007];
vi adj[2507];
map<pii,int>Ans;
int n , m , s ;
bool Vis[25007];
int pos ;
int last ;

struct node{
    int u,v;
}st[25007];

void bfs(int s ){
    queue<int>Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(Vis[u]) continue;
        Vis[u] = true ;
        forstl(i,adj[u]){
            int v = *i ;
            if( Vis[v] )continue ;
            Ans[ make_pair(u,v) ] = e[ pos++ ];
            Q.push(v);
        }
    }
}
int main() {
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int t = II ;
    For(cs,t){
        Ans.clear();

        cin >> n >> m >> s ;
        rep(i,m){
            int u , v , w ;
            cin >> u >> v >> w ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
            st[i].u = u;
            st[i].v = v;
            e[i] = w ;
        }
        For(i,n) sort(all(adj[i]));
        ms(Vis,false);
        int Cnt = n ;
        sort(e,e+m);
        last = m - 1 ;
        pos = 0;
        bfs(s);
        printf("Case %d:\n",cs);
        rep(i,m){
            int tmp  ;
            if(Ans.find(make_pair(st[i].u,st[i].v)) != Ans.end()) {
                tmp = Ans[make_pair(st[i].u,st[i].v)] ;
            }
            else if(Ans.find(make_pair(st[i].v,st[i].u)) != Ans.end()){
                 tmp = Ans[make_pair(st[i].v,st[i].u)] ;
            }
            else tmp = e[last--];
            cout << st[i].u << " " << st[i].v << " " << tmp << endl;
        }
        For(i,n) adj[i].clear();
    }
}
