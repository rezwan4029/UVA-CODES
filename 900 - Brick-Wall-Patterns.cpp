#include<stdio.h>

int main()
{
    long long f[100];
    f[1] = 1 , f[2] = 2;
    for(int i = 3 ; i <= 50 ; i++)
        f[i] = f[i-1] + f[i-2] ;
    int n ;
    while(scanf("%d",&n) && n!=0)
    {
        printf("%lld\n",f[n]);
    }
    return 0;
}
