#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
int n,x;
ll dp[25][151];
ll solve(int pos , int sum)
{
    if(pos > n )
    {
            if(sum >= x ) return 1;
            return 0 ;
    }

    ll &ret = dp[pos][sum];
    if(ret != -1) return ret;
    ret = 0 ;
    for(int i = 1 ; i <= 6 ; i++ )
    {
        ret += solve(pos+1,sum+i);
    }
    return ret;
}
int main()
{
    
    while(scanf("%d %d",&n,&x))
    {
        if( n == 0 && x == 0 ) break;
        memset(dp,-1,sizeof dp);
        ll comb = pow(6ll,n);
        ll ret = solve(1,0);
        ll g = __gcd(comb,ret);
        comb /=g;
        ret /=g;
        
        if( ret>=1 && comb > 1)  printf("%lld/%lld\n",ret,comb);
        else printf("%lld\n",ret);
    }
}
