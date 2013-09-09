#include <stdio.h>
#include <string.h>
int n , x , r , one ;
int main()
{
    int test , cs =1 ;
    
    scanf("%d",&test);
    while(test--)
    {
          scanf("%d",&n);
          r = one = 0 ;
          for( int i = 0 ; i < n ; i ++ ) {
               scanf("%d",&x);
               r ^= x ;
               if( x == 1 ) one ++ ;
          }
          if(r) puts("poopi") ;
          else{
               one != n ? puts("poopi") : puts("piloop");
          }
    }
}
