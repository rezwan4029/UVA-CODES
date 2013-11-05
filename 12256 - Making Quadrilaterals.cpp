/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll dp[65];

int main(){
    int n;
    dp[1] = dp[2] = dp[3]  = 1 ;
    for(int i = 4 ; i < 61 ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int cs = 1 ;
    while(scanf("%d",&n) && n){
        printf("Case %d: %lld\n",cs++,dp[n]);
    }
}
