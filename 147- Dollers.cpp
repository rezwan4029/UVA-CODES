#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30001
int coins[]= {5,10,20,50,100,200,500,1000,2000,5000,10000};
char num[15];
unsigned long long int dp[MAX];
int main()
{
    for(int i = 0; i < MAX; i++)dp[i]=0;
    dp[0]=1;
    for(int i = 0; i < 11; i++)
    {
        for(int j = coins[i] ; j <= MAX; j++)
            dp[j] += dp[ j - coins[i] ];
    }
    int n , i , j;
    while(gets(num))
    {
        sscanf(num,"%d.%d",&i,&j);
        if(i==0&& j==0)break;
        n= i*100 + j;
        printf("%3d.%.2d%17llu\n",i,j,dp[n]);
    }
    return 0;
}
