#include <stdio.h>
#define min(a,b) a<b?a:b
int main()
{
    int Test, n ,H,W,L;
    scanf("%d",&Test);
    while(Test--)
    {
        scanf("%d",&n);

        int minArea = 999999999 ;

        for( L = 1 ; L <= n ; L++)
                for( W = 1 ; W <= n ; W++ ){

                    if(L*W > n )break;

                    for( H = 1 ; H <= n ; H++ ){

                            if( L*W*H > n )break;

                            if( L*W*H == n) minArea = min( minArea ,  2*(L*W + W*H + L*H )  );
                    }
        }
        printf("%d\n",minArea);
    }
    return 0;
}
