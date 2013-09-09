#include <stdio.h>
#include <string.h>
#define inf -999999
#define max(a,b) a > b ? a: b
int mxMoney,Garments;
int price[22][22];
int perGermentItems[22];
int dp[22][202];

int solve( int currGerment , int CurrMoney)
{
    if( CurrMoney > mxMoney ) return inf ;
    if( currGerment > Garments ) return CurrMoney ;
    int &ret = dp[currGerment][CurrMoney];
    if( ret != -1) return ret ;
    ret  = inf ;
    for( int i = 1 ; i <= perGermentItems[ currGerment ] ; i++ ) {
         ret = max( ret , solve( currGerment + 1 , CurrMoney + price[currGerment][i]));       
    }
    return ret ;   
}
int main()
{
    int test , cs = 1 ;
    scanf("%d",&test);
    while(test--)
    {
      scanf("%d %d",&mxMoney,&Garments);
      for( int i = 1 ; i <= Garments ; i++ ){
               scanf("%d",&perGermentItems[i]);
               for( int j = 1 ; j <= perGermentItems[i] ; j++ ) scanf("%d",&price[i][j]);
      }
      memset(dp,-1,sizeof dp);
      int ret = solve(1,0);
      if( ret != inf ) printf("%d\n",ret);
      else puts("no solution");
    }
}
