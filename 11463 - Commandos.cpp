#include<stdio.h>
#define infinity 9999999
#define max(a,b)(a>b?a:b)
#define min(a,b)(a>b?b:a)
int d[105][105];
int n;
void clr()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j)d[i][j]=infinity;
            else d[i][j]=0;
}
int main()
{
    int u,v,t,m,cs=1;
    int i,j,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        clr();
        while(m--)
        {
            scanf("%d %d",&u,&v);
            d[u][v]=d[v][u]=1;
        }
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

        int src,dest;
        scanf("%d %d",&src,&dest);

        int ans=-1;
    
        for(i=0;i<n;i++)
                ans=max(ans, d[src][i]+d[i][dest] );

        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
