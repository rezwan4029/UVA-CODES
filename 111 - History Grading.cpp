#include <stdio.h>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int dp[ 22 ][ 22 ];
int  a[ 22 ],b[ 22 ];
int n,m;
int lcs(int i,int j)
{
    if( i > n || j > n ) return 0;

    int &ret = dp[i][j];

    if( ret != -1 ) return ret;

    if(a[i] == b[j] ) ret = lcs( i+1 ,j+1 ) +1 ;

    else    ret  = max( lcs(i+1,j) , lcs(i,j+1) );

    return ret ;
}

int main()
{
    int i,j,x;
    scanf("%d",&n);
    for(int i  = 1 ; i <= n ;i++){
            scanf("%d",&x);
            a[ x ] = i;
    }
    while(~scanf("%d",&m)){
            b[m] = 1;
            for( j = 2 ; j<= n ;j++) {scanf("%d",&x);
                b[ x ] = j;
            }
            memset(dp,-1,sizeof dp);
            int ret = lcs(1,1);
            cout << ret  << endl;
    }
}
