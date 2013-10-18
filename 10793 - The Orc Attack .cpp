/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-9
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const int INF = 1<<29 ;
const int MX = 105 ;

int N , M , dp[MX][MX];

void Init(){
    For(i,100){
        For(j,100) dp[i][j] = INF ;
        dp[i][i] = 0 ;
    }
}

void makeGraph(){
    while(M--){
        int u = II , v = II , c = II ;
        dp[u][v] = dp[v][u] = min( dp[u][v] , c );
    }
}

void Warshall(){
    For(k,N)
        For(i,N)
            For(j,N)
                dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k][j] );
}
int getAns(){
    int ret = INF ;
    For(i,N){
        if(dp[i][1] == dp[i][2] && dp[i][2] == dp[i][3] && dp[i][3] == dp[i][4] && dp[i][4] == dp[i][5]){
            if(dp[i][1] == INF )return -1 ;
            int mx = dp[i][1];
            forab(j,2,N) mx = max(mx,dp[i][j]);
            ret = min(ret,mx);
        }
    }
    return ret == INF ? -1 : ret  ;
}
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
 //   cout << INF << endl;
    int test = II ;
    For(cs,test){
        N = II , M = II ;
        Init();
        makeGraph();
        Warshall();
        printf("Map %d: %d\n",cs,getAns());
    }
}
