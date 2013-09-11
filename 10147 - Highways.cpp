#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct edge
{
    int u,v;
    double w;
} E;
int prev[1005];
int getParent(int i)
{
    if(i==prev[i]) return i;

    return (prev[i]=getParent(prev[i]));
}

int isUnion(int a,int b)
{
    return getParent(a)==getParent(b);
}

void makeUnion(int a,int b)
{
    prev[getParent(a)] = getParent(b);
}

int cmp(const void*a,const void*b)
{
    if((*(E*)a).w<(*(E*)b).w) return -1;
    return 1;
}
double distance(int x1,int y1,int x2,int y2)
{
    return (sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ));
}
int main()
{
    int n,e,i,d,t,s,j;
    double mst;
    E x[300000];
    int dx[1005],dy[1005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d ",&n) ;

        for(i=1; i<=n; i++)prev[i]=i;
        for(i=1; i<=n; i++)
            scanf("%d %d",&dx[i],&dy[i]);
        e=0;
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
            {
                x[e].u=i;
                x[e].v=j;
                x[e].w=distance(dx[i],dy[i],dx[j],dy[j]);
                e++;
            }
        int ed,p,q;
        scanf("%d",&ed);
        d =0;

        for(i=0; i<ed; i++)
        {
            scanf("%d %d",&p,&q);
            if(!isUnion(p,q))
            {
                makeUnion(p,q);
                d++;
            }
        }
        if(d==n-1)
        {
            printf("No new highways need\n\n");
            continue;
        }
        qsort(x,e,sizeof(E),&cmp);

        for(i=0; i<e && d<n-1; i++){
            if(!isUnion(x[i].u,x[i].v)){
                printf("%d %d\n",x[i].u,x[i].v);
                makeUnion(x[i].u,x[i].v);
                d++;
            }
        }
        if(t)printf("\n");
    }
    return 0;
}
