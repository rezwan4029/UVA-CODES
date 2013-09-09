#include <stdio.h>
#define MAX 10001
int coins[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
char num[15];
unsigned long long int ways[MAX];

int main()
{
    int i,j,n,coin;
    for(i=0;i<MAX;i++)ways[i]=0;
    ways[0]=1;
    for(i=0;i<21;i++)
    {
        coin = coins[i];
        for(j=coin;j<=MAX;j++)
                ways[j]+=ways[j-coin];
    }
    while(scanf("%d",&n)==1)
    {

        printf("%llu\n",ways[n]);
    }
    return 0;
}

