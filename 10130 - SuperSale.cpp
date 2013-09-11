#include<stdio.h>
#define max( a, b ) ( a > b ? a : b )
#define MAX 1005


int N,MW,C[MAX][MAX],V[MAX],W[MAX];


int Knapsack()
{
    int i , w ;
    
    for (i=0; i<=N ; i++) C[i][0] = 0;
    for (w=0; w<=MW; w++) C[0][w] = 0;

    for (i=1; i<=N; i++)
    {
        for(w=0; w<=MW; w++)
        {
            if (W[i] > w) C[i][w] = C[i-1][w];
            else C[i][w] = max( C[i-1][w] , C[i-1][w-W[i]] + V[i]);
        }
    }
    return C[N][MW];
}

int main()
{
    int sum,MW_num,i,y,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(i=1; i<=N; i++) scanf("%d%d",&V[i],&W[i]);
        sum=0;
        scanf("%d",&MW_num);
        while(MW_num--)
        {
            scanf("%d",&MW);
            sum+=Knapsack(); //sum of all knapsack
        }
        printf("%d\n",sum);
    }
    return 0;
}
