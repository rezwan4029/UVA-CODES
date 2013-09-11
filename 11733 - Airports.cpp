/*
Author : Rezwanul Islam Maruf
AUST ,CSE
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct edge
{

    int u,v,w;
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


int main()
{
    int t,n,e,i,d,j,cs=1,cost,mst;
    E x[100002];
    int visited[100002];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&e,&cost);

        for(i=0;i<e;i++)
            scanf("%d %d %d",&x[i].u,&x[i].v,&x[i].w);

        qsort(x,e,sizeof(E),&cmp);

        for(i=1;i<=n;i++)prev[i]=i;

        mst=d=0;
        for(i=0;i<e && d<n-1 && x[i].w<cost;i++)
        {
            if(!Link(x[i].u,x[i].v))
            {
                d++;
                makeUnion(x[i].u,x[i].v);
                mst=mst+x[i].w;
            }
        }
        int cnt=0;
        for(i=1;i<=n;i++)if(prev[i]==i)cnt++;

        cost = mst + cost*cnt;
        printf("Case #%d: %d %d\n",cs++,cost,cnt);

    }
    return 0;
}
