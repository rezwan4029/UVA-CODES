#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for(__typeof(n)i = 0 ; i < n ; i++ )
#define FOR(i,n) for(__typeof(n)i = 1 ; i <=n ; i++ )

vector < int > edges[ 105 ];
bool V[105];
int deep;
void dfs(int u )
{
    V[u] = true;
    deep++;
    REP(i,edges[u].size()) if( !V[ edges[u][i] ]) dfs(edges[u][i]);
}
int main()
{
    int n , d[105];
    while(scanf("%d",&n)==1 && n)
    {
        FOR(i,n)
        {
            d[i] = 0;
            edges[i].clear();
            int go,x;
            scanf("%d",&go);
            while(go--)
            {
                scanf("%d",&x);
                edges[i].push_back(x);
            }
        }

        int mxDepth = -1 ,minNode = 1 ;

        FOR(i,n)
        {
            memset(V,false,sizeof V) ;
            deep = 0;
            dfs(i);
            d[i] = deep ;
        }

        FOR(i,n) mxDepth = max(mxDepth,d[i]);
        FOR(i,n) if(d[i] == mxDepth ) {
             minNode = i ;
             break;
        }
        printf("%d\n",minNode);
    }
    return 0;
}
