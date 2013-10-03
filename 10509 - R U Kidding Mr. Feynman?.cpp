#include<stdio.h>

int main(){
    double n , ans , dx ;
    int i ;
    while( scanf("%lf",&n) ){
        if( n == 0 ) break ;
        for(i = 1 ; ; i++ ){
            if(  i*i*i > n ) {
                ans =  i - 1 ;
                break ;
            }
        }
        dx = ( n - ( ans * ans * ans ) ) / ( 3 * ans * ans );
        printf("%.4lf\n",ans + dx );
    }
}
