#include <stdio.h>
#include <string.h>
#define min(a,b) a > b ? b: a

void on( int &mask ,int pos){
     mask |= ( 1 << pos) ;
}
void  off(int &mask,int pos){
    mask = mask & ~( 1 << pos) ;
}
bool check( int mask , int pos ){
     return bool( mask & ( 1 << pos) ) ;
}
int dp[ 1<<12 + 5 ] ;

int solve( int mask)
{
    int &ret = dp[mask];
    if( ret != -1 ) return ret;
    ret = __builtin_popcount(mask);
    for( int pos = 0 ; pos < 12 ; pos ++ )
    {
         if( pos < 10 && check(mask,pos) && check(mask,pos+1) && !check(mask,pos+2)){
              int newmask = mask;
              off(newmask,pos) , off( newmask , pos +1 ) , on(newmask,pos+2);
              ret = min( ret , solve(newmask));
         }
         if( pos > 1 && check(mask,pos) && check(mask,pos-1) && !check(mask,pos-2)){
             int newmask = mask;
             off(newmask,pos) , off( newmask , pos-1 ) , on(newmask,pos-2);
             ret = min( ret , solve(newmask));
         }      
   }
   return ret;
}
int main()
{
    int test , cs = 1 ;
    char s[20];
    scanf("%d",&test);
    while(test--)
    {
      scanf("%s",&s);
      memset(dp,-1,sizeof dp);
      int mask = 0 ;
      for(int i = 0 ; s[i] ; i++ ) if( s[i] == 'o') on(mask,i);
      int ret = solve(mask);
      printf("%d\n",ret);
    }
}
