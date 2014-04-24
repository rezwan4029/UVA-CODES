#include <stdio.h>
int main() {
    int T , cs , n , k , x , s , rem , c ;
    scanf("%d",&T);
    for( cs = 1 ; cs <= T ; cs++ ) {
        scanf("%d %d %d",&n,&k,&x);
        s = rem = 0 ;
        for( c = 0 ; c < k ; c++ ){
            rem += x ;
            x++;
        }
        s = ( n * ( n + 1 ) ) >> 1 ;
        printf("Case %d: %d\n",cs,s-rem);
    }
}
