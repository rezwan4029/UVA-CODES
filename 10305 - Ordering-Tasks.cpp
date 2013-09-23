#include <cstdio>
#include <queue>
#define MAX 105
using namespace std;

int adjMat[MAX][MAX];
int vertices, ts[MAX], rank[MAX];

int topsort()
{
    int i, v, w;
    queue<int> q;

    for(v = 1 ; v <= vertices ; v++)  if(rank[v] == 0) q.push(v);
        
    for( i = 1 ; !q.empty() ; i++)
     {
        ts[i] = v = q.front();
        q.pop();
        for(w = 1 ; w <= vertices ; w++){
            if(adjMat[v][w] && --rank[w]==0)
                q.push(w);
        }
    }
    return i;
}

int main()
{
    int n, m, i, j, x;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)break;
        vertices = n;
        for(i=1;i<=n;i++)rank[i]=0;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++) adjMat[i][j]=0;
        while(m--)
        {
            scanf("%d %d", &i, &j);
            adjMat[i][j] = 1;
            rank[j]++;
        }
        x = topsort();
        printf("%d",ts[1]);
        for(i=2; i<x; i++) printf(" %d", ts[i]);
        printf("\n");
    }

    return 0;
}
