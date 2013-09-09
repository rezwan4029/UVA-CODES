#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cstring>
#define  DB double
#define SQ(a) ((a)*(a))
using namespace std;

typedef struct edge
{

    int u,v;
    DB w;
}E;

int prev[10002];
int Parent(int i)
{
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

int Link(int a,int b)
{
    return Parent(a)==Parent(b);
}

void makeUnion(int a,int b)
{
    prev[Parent(a)] = Parent(b);
}

int cmp(const void*a,const void*b)
{
    if((*(E*)a).w<(*(E*)b).w) return -1;
    else  return 1;
}

DB calc(DB a, DB b, DB c,DB d)
{
    DB ans=sqrt(SQ(a-c)+SQ(b-d));
    return ans;
}

int main()
{
    int t,n,e,i,d,j,cs=1;
    E x[100002];
    int visited[100002];
    scanf("%d",&t);
    double dist[1005][2],mst;
    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++) scanf("%lf %lf",&dist[i][0],&dist[i][1]);

        e=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                {
                  x[e].u =i;
                  x[e].v =j;
                  x[e].w= calc(dist[i][0],dist[i][1],dist[j][0],dist[j][1]);
                  e++;
                }

        qsort(x,e,sizeof(E),&cmp);

        for(i=0;i<n;i++)prev[i]=i;

        mst=d=0;

        for(i=0;i<e && d<n-1;i++)
        {
            if(!Link(x[i].u,x[i].v))
            {
                d++;
                makeUnion(x[i].u,x[i].v);
                mst=mst+x[i].w;
            }
        }

        printf("%.2lf\n",mst);
        if(t)printf("\n");

    }

    return 0;
}


