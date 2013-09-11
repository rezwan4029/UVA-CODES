#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct edge
{
    int u,v;
    double w;
} E;
int prev[510];
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
    E x[200005];
    int dx[510],dy[510];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&s,&n) ;

        for(i=0; i<n; i++)prev[i]=i;
        for(i=0; i<n; i++)
            scanf("%d %d",&dx[i],&dy[i]);
        e=0;
        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
            {
                x[e].u=i;
                x[e].v=j;
                x[e].w=distance(dx[i],dy[i],dx[j],dy[j]);
                e++;
            }


        qsort(x,e,sizeof(E),&cmp);

        d =mst= 0;
        for(i=0; i<e && d<n-s; i++)

            if(!isUnion(x[i].u,x[i].v))
            {
                makeUnion(x[i].u,x[i].v);
                if(mst<x[i].w)mst=x[i].w;
                d++;
            }

        printf("%.2lf\n",mst);

    }
    return 0;
}
