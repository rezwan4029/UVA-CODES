#include<stdio.h>
#define infinity 9999999
#define max(a,b)(a>b?a:b)
#define min(a,b)(a>b?b:a)
int d[105][105];
int n;
void clr()
{
    int i,j;
    for(i=1;i<=100;i++)
        for(j=1;j<=100;j++)
            if(i!=j)d[i][j]=infinity;
            else d[i][j]=0;
}
int main()
{
    int u,v,cs=1;
    int i,j,k;
    while(scanf("%d %d",&u,&v))
    {
        if(u==0 && v==0)break;
        clr();
        d[u][v]=1;
        n=max(u,v);
        while(scanf("%d %d",&u,&v))
        {
            if(u==0 && v==0)break;
            n=max(n,max(u,v));
            d[u][v]=1;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                    
        double sum=0,pg=0;
        
        for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                        if(d[i][j]<infinity && d[i][j])sum=sum+d[i][j],pg++;
                      
            
        printf("Case %d: average length between pages = %.3lf clicks\n",cs++,sum/pg);

    }
    return 0;
}
