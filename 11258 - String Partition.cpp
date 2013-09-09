/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<sstream>
#include<set>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define INF 2147483647

char S[207];
ll dp[207],n;

ll solve(int pos)
{
    if(pos == n ) return 0;
    ll &ret = dp[ pos ];
    if( ret != -1 ) return ret;
    ll sum = 0;
    ret = 0 ;

    For(digit,10)
    {
       if( digit + pos > n ) break ;
       sum  = sum * 10 + S[ pos + digit - 1 ] - '0';
       if( sum > INF ) break ;

       ret = max( ret , solve(pos+digit) + sum  );
    }
    return ret ;
}

int main()
{
   int T ; scanf("%d",&T);

   while(T--)
   {
       scanf("%s",&S);
       memset(dp,-1,sizeof dp);
       n = strlen(S) ;
       ll ans = solve(0);
       printf("%lld\n",ans);
   }
}
