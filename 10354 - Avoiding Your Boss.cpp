#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int inf = (1<<29);
int d[100][100];
int d2[100][100];
int USED[100],n;

void FLOYD(int mat[100][100])
{
    int i,j,k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
}

int solve(int b,int o,int y,int m)
{
    FLOYD(d);
    int i,j,k;
    for(i=0; i<n; i++)
    {
        if (d[b][i]+d[i][o] == d[b][o])USED[i]=1;
    }
    for(i=0; i<n; i++)
    {
        if (!USED[i])continue;

        for(j=0; j<n; j++)
            d2[i][j]=d2[j][i]=inf;

    }
    FLOYD(d2);
    return d2[y][m];
}

int main()
{
    int e,b,o,y,m,i,j,k;
    while(cin>>n>>e>>b>>o>>y>>m)
    {
        b--,o--,y--,m--;
        for(i=0; i<n; i++)
        {
            USED[i]=0;
            for(j=0; j<n; j++)
                d[i][j]=d2[j][i]=inf;
            d[i][i]=d2[i][i]=0;
        }
        for(i=0; i<e; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            d[u][v] = d[v][u]=d2[u][v] =d2[v][u]=w;
        }
        int ans=solve(b,o,y,m);
        if (ans == inf)cout <<"MISSION IMPOSSIBLE."<<endl;
        else cout << ans << endl;
    }
    return 0;
}
