#include <stdio.h>
long long int dp[7500];
int coins[] = {1,5,10,25,50};
int main(){
    dp[0] = 1;
    for(int i = 0; i < 5; i++){
        for(int j = coins[i] ; j <= 7489 ; j++)
            dp[j] += dp[ j - coins[i] ];
    }
    int n ;
    while( scanf("%d",&n) == 1 ) printf("%lld\n",dp[n]);
}
