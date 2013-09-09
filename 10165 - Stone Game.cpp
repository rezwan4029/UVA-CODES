#include <stdio.h>
#include <string.h>
int n , x , r  ;
int main()
{

    while(scanf("%d",&n) && n )
    {
          
          r = 0;
          for( int i = 0 ; i < n ; i ++ ) {
               scanf("%d",&x);
               r ^= x ; 
          }
   
          r? puts("Yes") : puts("No");
    }
}
