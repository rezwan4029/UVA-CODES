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

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

const int MX = 102 ;
int dp[MX][MX];

const int INF = 1000000;

int main()
{
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int N ;
    while( scanf("%d",&N) == 1 ){
        rep(i,N){
            string Str ;
            rep(j,i){
                if( j == i ) { dp[i][i] = 0 ; continue ; }
                cin >> Str ;
                if( Str[0] != 'x' ) dp[i][j] = dp[j][i] = toInt(Str) ;
                else  dp[i][j] = dp[j][i] = INF ;
            }
        }
//        rep(i,N){ rep(j,N) printf("%10d ",dp[i][j]); cout << endl;  }
        rep(k,N)rep(i,N)rep(j,N) dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k][j] );

  //      puts("\n\n");

    //    rep(i,N){ rep(j,N) cout << dp[i][j] << "   "; cout << endl;  }
        int ans = 0 ;
        rep(i,N) if(dp[0][i] != INF ) ans = max(ans,dp[0][i]);
        printf("%d\n",ans);
    }
}
