#include<stdio.h>

long long int SumOfDivisors(long long int n)
{
    long long int i,y,z,ans = 0;

    for(i = 2, y = n; i <= n / i;i++){
          z = y;
          y = n / i;
          ans += i * (y - 1);
          ans += (long long int)(i - 2) * (y + 1 + z) * (z - y) / 2;
    }
    
    if(i <= y) ans += i * (n / i - 1);
    
    return ans;
}

int main(){
    int t , cs=1;
    long long int n;
    while(scanf("%lld",&n)&&n)
              printf("Case %d: %lld\n",cs++,SumOfDivisors(n));
    return 0;
}
