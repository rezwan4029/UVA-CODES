/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

#define MX 130

int N , M , K , D ;

struct point{
    int x , y ;
    point(int _x , int _y ){
        x = _x , y = _y ;
    }
    point(){}
};

int dis(point a , point b ){
    int r = ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) ;
    return r ;
}

point doctor[MX];
point tree[MX][MX];
int branch[MX];
vi E[MX];
bool Vis[MX];

void buildGraph(){

    rep(i,N){
        rep(b1,branch[i]){
            forab(j,i+1,N-1){
                rep(b2,branch[j]){
                    int Cost = dis( tree[i][b1] , tree[j][b2] ) ;
                    if( Cost <= K ){
                        E[ M + i ].pb( M + j ) ;
                        E[ M + j ].pb( M + i ) ;
                        b2 = branch[j];
                    }
                }
            }
        }
    }

    rep(i,M){
        rep(j,N){
            rep(b,branch[j]){
                int Cost = dis( tree[j][b] , doctor[i] ) ;
                if( Cost <= D ){
                    E[i].pb( M + j ) ;
                    E[M + j ].pb( i );
                    b = branch[j];
                }
            }
        }
    }
}

void dfs(int u){
    if(Vis[u]) return ;
    Vis[u] = true ;
    forstl(it,E[u]) dfs(*it);
}

void Reset(){
    rep(i,MX){
        E[i].clear();
        Vis[i] = false ;
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    int test = II ;
    For(cs,test){
            N = II , M = II , K = II , D = II ;
            K = K * K , D = D * D ;
            rep(i,M){
                doctor[i].x  = II ,  doctor[i].y = II  ;
            }
            rep(i,N){
                branch[i] = II ;
                rep(b,branch[i]){
                    tree[i][b].x = II , tree[i][b].y = II ;
                }
            }
            buildGraph();
            dfs(M);
            bool save = false ;
            rep(i,M) save |= Vis[i];
            if(save) puts("Tree can be saved :)");
            else puts("Tree can't be saved :(");
            Reset();
    }
}
