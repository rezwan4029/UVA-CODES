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

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

#define SZ 1007

int N , M , d[SZ][SZ] ;
int Mat[SZ][SZ];
const int INF = 100000;

struct Node{
    int x , y , w ;
    Node(){}
    Node(int _x  , int _y, int _w){
        x = _x , y = _y , w = _w ;
    }
    bool operator <(const Node &a) const{
        return (w > a.w);
    }
};

void Reset(){
    rep(i,N+1)rep(j,M+1) {
        d[i][j] = INF ;
    }
}

bool isValid(int p , int q ){
    if( p >= 0 && p < N && q >=0 &&q < M ) return true ;
    return false ;
}

void Dijstra(int srcX , int srcY ){
    priority_queue<Node>Q;
    d[srcX][srcY] = Mat[srcX][srcY] ;
    Q.push( Node(srcX,srcY,Mat[srcX][srcY]) );
    while(!Q.empty()){
        Node now = Q.top(); Q.pop();

        //cout << now.w << "   " << d[ now.x ][ now.y ] << endl;

        rep(i,4){
            int nxtNodeX = dx[i] + now.x , nxtNodeY = dy[i] + now.y ;
            if( isValid(nxtNodeX,nxtNodeY) && ( d[nxtNodeX][nxtNodeY] > now.w + Mat[nxtNodeX][nxtNodeY] ) ){
                d[nxtNodeX][nxtNodeY] = now.w + Mat[nxtNodeX][nxtNodeY] ;
                Q.push( Node( nxtNodeX ,nxtNodeY, d[nxtNodeX][nxtNodeY] ) );
            }
        }
    }
}


int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        N = II , M = II ;
        rep(i,N)rep(j,M) Mat[i][j] = II ;
        Reset();
        Dijstra(0,0);
      //  rep(i,M-1) cout << d[N-1][i] << endl;
        printf("%d\n",d[N-1][M-1]);
    }
}
