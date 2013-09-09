#include <stdio.h>
#include <string.h>
#define inf 999999
#define max(a,b) a > b ? a : b
int n ;
int dp[105][105];
int a[105],sum[105];

int SUM(int i , int j){
    return sum[j]-sum[i-1];
}
int solve( int l , int r )
{

    if(l > r) return 0;
    if(l == r) return a[l];

    int &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = -inf ;

    for( int i = l ; i <= r ; i++ ){

        ret = max(  ret , SUM(l,i) - solve(i+1,r) );
        ret = max(  ret , SUM(i,r) - solve(l,i-1) );
    }

    return ret;
}
int main()
{

    while(scanf("%d",&n) && n){
    memset(sum,0,sizeof sum);
    for(int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
        sum[ i ] = sum[ i-1 ] + a[i] ;
    }
    memset(dp,-1,sizeof dp);
    int ret = solve(1,n);

    /*
    for( int i = 0 ; i<n ;i++)
            {for( int j = 0 ; j < n ; j++)
                printf("%5d",dp[i][j][0]);
        puts("");
    }
    puts("..................");
    for( int i = 0 ; i<n ;i++)
            {for( int j = 0 ; j < n ; j++)
                printf("%5d",dp[i][j][1]);
        puts("");
        */

        printf("%d\n",ret);
    }

}
