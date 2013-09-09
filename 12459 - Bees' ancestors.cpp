#include <stdio.h>

int main(){
    long long n , f[85];
    f[1] = 1 , f[2] = 2;
    for( n = 3 ; n <= 80 ; n++ ) f[n] = f[n-1] + f[n-2] ;
    while( scanf("%lld",&n) &&n ) printf("%lld\n", f[n] ) ;
}
