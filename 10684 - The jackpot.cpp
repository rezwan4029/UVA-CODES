#include <stdio.h>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int n ,x  ;
    int a[10005],dp[10005];

    while(scanf("%d",&n) && n)
    {
        for( int i = 0 ; i<n ;i++ ){
            scanf("%d",&a[i]);
            dp[i] = 0;
        }
        dp[0] =a[0];
        for( int i = 1 ; i < n ;i++ ){
            if( a[i] + dp[ i-1] > a[i] ){
                dp[i] = a[i] + dp[i-1];
            }
            else    dp[ i ] = a[i];
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++ ) ans = max( dp[i] , ans );
        if(ans)printf("The maximum winning streak is %d.\n",ans);
        else   puts("Losing streak.");
    }
    return 0 ;
}
