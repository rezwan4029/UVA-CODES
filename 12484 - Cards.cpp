#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)

ll dp[10004][2];
ll  a[10004];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        rep(i,n)scanf("%lld",a+i);
        memset(dp,0,sizeof dp);
        bool player = true;
        rep(len,n)
        {
            player = !player ;
            for( int j = 0 ; j + len < n ; j++ )
            {
                if(player) dp[j][player] = max( a[j] + dp[j+1][!player] , a[j+len] + dp[j][!player] );
                else  dp[j][player] = min( dp[j+1][!player] , dp[j][!player] );
            }
        }
        printf("%lld\n",dp[0][1]);
    }
    return 0;
}
