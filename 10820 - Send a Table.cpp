#include <stdio.h>
#include <iostream>
using namespace std;
#define i64 long long
i64 PHI[50002];
i64  phi ( i64  n ) {
	i64  i,result = n ;
	for (  i = 2 ; i * i <= n ; ++ i )
		if ( n % i == 0 ) {
			while ( n % i == 0 )
				n /= i ;
			result =result- result / i ;
		}
	if ( n > 1 )
		result -= result / n ;
	return result ;
}
int main()
{
    PHI[0]=0;
    for(int i = 1 ; i <= 50000 ; i++ ){
        PHI[i] += PHI[i-1] + phi(i);
    }
    int n;
    while( scanf("%d",&n) && n)
    {
        printf("%lld\n",PHI[n]*2 -1 );
    }
}
