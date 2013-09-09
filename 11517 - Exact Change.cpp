
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

int dp[100007];
int coin[107];

int main()
{
    int Test = II ;
    while(Test--)
    {
        int sum = II , n = II ;
        rep(i,n) coin[i] = II ;
        ms(dp,0);
        dp[0]= 1;
        rep(i,n)for(int j = 10000 ; j >= 0 ; j--){
            if( dp[j] ) {
                dp[ j + coin[i]  ] = min( dp[ j+coin[i]  ] , dp[ j ] + 1 ) ;
                if(dp[ j+coin[i] ] == 0 ) dp[ j+coin[i] ] = dp[j] + 1 ;
            }
        }
        int s = sum ;
        for(; s <= 10000 ; s++)if(dp[s])break;
        printf("%d %d\n",s,dp[s]-1);
    }
}
