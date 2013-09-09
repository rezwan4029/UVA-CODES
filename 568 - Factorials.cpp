#include <stdio.h>

long long fact(long long n)
{
    long long i,sum=1;
    
    for(i=2; i<=n; i++) {
        sum = sum * i;
        while((sum%10)==0) {
            sum = sum/10;
        }
        sum = sum % 100000;
    }
    return sum % 10;
}

int main(){
    int n;
    while(scanf("%d", &n)==1){
        printf("%5d -> %d\n", n, fact(n));
    }
    return 0;
}

