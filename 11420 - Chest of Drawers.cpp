#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define ll long long
using namespace std;

#define lock 0
#define unlock 1


ll dp[70][70][2];

ll solve(int pos ,int cntSecure,int prev)
{
    if( pos < 0 || cntSecure < 0 || prev < 0 )return 0;

    else if( pos == 0 && cntSecure ==0 )    return 1;

    ll &ret =dp[pos][cntSecure][prev];
    if(ret != -1 )return ret ;

    if(prev == lock) ret = solve(pos-1,cntSecure-1,lock) + solve(pos-1,cntSecure,unlock);
    else             ret = solve(pos-1,cntSecure,lock)   + solve(pos-1,cntSecure,unlock);

    return ret;

}

int main()
{
    int n , s ;
     
    memset(dp,-1,sizeof dp);
    
    while(scanf("%d %d",&n,&s)){

        if( n < 0  )break;

        ll ret = solve(n,s,lock);

        printf("%lld\n",ret);
    }
}
