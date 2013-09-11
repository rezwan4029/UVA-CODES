#include<stdio.h>
#include<vector>
#include<string.h>
#include<iostream>
#define sz 10010
using namespace std;
vector<int>adj[sz];
bool V[sz];
void DFS(int u)
{
    V[u]=true;
    for(size_t i=0;i<adj[u].size();i++)
    {
        if(!V[ adj[u][i] ])DFS(adj[u][i]);
    }
}
int main()
{
    int T,n,m,k,i,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        
        memset(V,false,sizeof V);
        
        for(i=1;i<=m;i++)
        {
            scanf("%d %d ",&u,&v);
            adj[u].push_back(v);
        }

        for(i=1;i<=k;i++)
        {
            scanf("%d",&u);
            DFS(u);
        }
        int ans=0;
        adj[0].clear();
        for(i=1;i<=n;i++)
        {
            if(V[i])ans++;
            adj[i].clear();
        }
        cout<<ans<<endl;

    }
    return 0;
}
