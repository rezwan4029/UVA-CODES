/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ninf (-pinf)
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define LL long long
#define LLU unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define inpI ({int a; scanf(" %d", &a); a;})
#define inpD ({DB a; scanf(" %lf", &a); a;})
#define inpLL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795

int aComp(const void * a, const void * b)
{
    return (*(int*)a-*(int*)b );
}
int dComp(const void * a, const void * b)
{
    return (*(int*)b-*(int*)a );
}
//qsort (array,size, sizeof(int), aComp);

#define sz 105
using namespace std;

int d[sz][sz];

int main()
{
    int n,src,u,v,w,cs=1;
    int i,j,k;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&src);

        for( i=1; i<=n; i++)
            for( j=1; j<=n; j++)
            {
                if(i==j)d[i][j]=0;
                else    d[i][j]=-inf;
            }

        while(scanf("%d %d",&u,&v))
        {
            if(u==0 && v==0)break;
            d[u][v]=1;
        }

        for( k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for( j=1; j<=n; j++)
                    d[i][j]=max(d[i][j],d[i][k]+d[k][j]);

        int ans=-1;
        int dest;
        for(i=1; i<=n; i++)
        {
            if(d[src][i]>ans)ans=d[src][i],dest=i;
        }
        CS;
        printf("The longest path from %d has length %d, finishing at %d.\n\n",src,ans,dest);

    }
    return 0;
}


//using bellman

typedef struct
{
    int u,v,w;
} Edge;

int d[1005];
Edge edge[2005];
int n, m,src;

void BellmanFord(int source)
{
    int i, j;

    msn(d,-inf);

    d[source] = 0;

    for(i=0; i<=n-1; i++)
        for(j=0; j<m; j++)
            if(d[edge[j].v] < d[edge[j].u]+edge[j].w)
            {
                d[edge[j].v] = d[edge[j].u]+edge[j].w;
            }

}

int main()
{
    int t , i , cs = 1 ;
    
    while(scanf("%d",&n)&&n)
    {
        src=inpI;
        //nodes are from 0-n-1
        m=0;
        for(;;)
        {
            int p=inpI,q=inpI;
            if(p==0 && q==0)break;
            edge[m].u=p;
            edge[m].v=q;
            edge[m].w=1;
            m++;
        }
        BellmanFord(src);// calling with src where src=0
        int end=src,ans=0;
        for(i=1; i<=n; i++)
        {
            if(d[i]>ans)
            {
                ans=d[i];
                end=i;
            }
        }
        CS;
        printf("The longest path from %d has length %d, finishing at %d.\n\n",src,ans,end);
    }
    return 0;
}
