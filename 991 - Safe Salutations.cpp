#include<stdio.h>
#define LL long long
LL nCr[35][35];
void combination() {
    int i,j;
    nCr[0][0] = 1;
    for(i=1;i<=25;i++) {
        nCr[i][0] = 1;
        for(j=1;j<=i;j++) {
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
        }
    }
}
int main()
{
    int n,t=0;

    combination();

    while(scanf("%d",&n)!=EOF)
    {
        if(t)printf("\n");t=1;
        printf("%lld\n",nCr[n<<1][n]/(n+1));

    }
    return 0;
}
