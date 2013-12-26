/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 107 ;
const int INF = 1e8 + 7;

const int inf = 1e8 + 7 ;

int N ;
int dp[MX][MX];
int main(){
    #ifdef LOCAL
      freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    while( scanf("%d",&N) && N ) {
        ms(dp,0);
        int m = 0 ;
        rep(i,N) {
            int x = II , y = II ;
            dp[x][y]++;
            m = max(max(m,x),y);
        }
        int Ans = 0 ;
        For(i,m) For(j,m) {
                dp[i][j] += max( dp[i-1][j] , dp[i][j-1] );
                Ans = max( dp[i][j] , Ans );
        }
        printf("%d\n",Ans);
    }
    printf("*\n");
}
