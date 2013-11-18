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
E x[1000001];

int prev[1000001];
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

    int t,n,e,i,d,j,mst,cs=1;


   // int visited[25001];

    while(scanf("%d",&n)==1)

    {
        e=n-1;
        if(cs!=1)printf("\n");cs++;

        int a,b,c,sum=0;


        for(i=0;i<e;i++)

           {
               //scanf("%d %d %d",&x[i].u,&x[i].v,&x[i].w);
               scanf("%d %d %d",&a,&b,&c);

               sum+=c;
           }
        printf("%d\n",sum);

        int k,m;

        scanf("%d",&k);


        for(i=0;i<k;i++)

               scanf("%d %d %d",&x[i].u,&x[i].v,&x[i].w);


        scanf("%d",&m);

        for(j=0;j<m;j++,i++)

               scanf("%d %d %d",&x[i].u,&x[i].v,&x[i].w);


        e=m+k;

        qsort(x,e,sizeof(E),&cmp);


        for(i=0;i<=n;i++)prev[i]=i;


        mst=d=0;
     //   for(i=0;i<e;i++) visited[i]=0;


        for(i=0;i<e && d<n-1;i++)

        {
            if(!Link(x[i].u,x[i].v))

            {
                d++;
                makeUnion(x[i].u,x[i].v);

                mst+=x[i].w;
            }
        }

        printf("%d\n",mst);


    }

    return 0;
}
