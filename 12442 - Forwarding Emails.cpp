#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;

vector<int>adj[50002],compo[50002];
vector<int>order,vua[50002];
bool visited[50002];
int cost[50002];
int mxNode , mxCost ;
int dfs1(int u,int x)
{
    compo[x].push_back(u);
    visited[u]=true;
    int i ,sz = vua[u].size();
    for( i = 0 ; i < sz ; i++)
    {
        int v = vua[u][i];
        if(!visited[ v ]) dfs1( v,x );
    }

}

int dfs2(int u)
{
   // cout<<u<<"--->";
    visited[u]=true;

    int i , v, sz = adj[u].size();

    for( i = 0 ; i < sz ; i++ ){

            v = adj[u][i];

            if( visited[ v ] ) break;
            dfs2(v);
    }
    return v;
}

void dfs3(int u)
{
    order.push_back(u);

    visited[u] =true;

    int i ,sz = adj[u].size();

    for( i = 0 ; i < sz ; i++ ){

            int v = adj[u][i];

            if(visited[v] )return;

            dfs3(v);
    }
}

int dfs4( int u )
{
    if (!cost [u]) return cost [u] = dfs4 (adj [u][0]) + 1;
    return cost [u];
}

void cycle( vector<int> &my)
{
    order.clear();
    memset(visited,false,sizeof visited);

    int i, cycleNode = dfs2(my[0]);

    memset(visited,false,sizeof visited);

    dfs3(cycleNode);
    //cout<<cycleNode<<"    ";

    for( i = 0 ; i < order.size() ; i++ ){
        cost[ order[i] ]  = order.size() ;
    }

    int sz = my.size();

    for( i = 0 ; i < sz ; i++){

            int u = my[i];

            if( cost[u] == 0 ) dfs4(u);
    }


    for( i = 0 ; i < sz ; i++ ){

            if( cost[ my[i] ] > mxCost ){
                    mxCost = cost[ my[i] ];
                    mxNode = my[i];
            }
            else if(cost[ my[i] ] == mxCost ){
                    mxNode = min( mxNode , my[i] );
            }
    }

}

void clear(int n)
{
    mxNode  = 1, mxCost = -9999999;
    for( int i = 0 ; i <= n ;i++ ){
        vua[i].clear();
        adj[i].clear();
        cost[i]= 0;
        visited[i]=false;
        compo[i].clear();
    }
}

int main()
{
    int t,i,j,cs=1;
    cin>>t;
    while(t--)
    {
        int n;

        cin>>n;

        clear(n);
        for(i=1; i<=n; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            vua[u].push_back(v);
            vua[v].push_back(u);
        }
        int totalCompo = 0;
        for( i = 1 ; i <= n ; i++)
        {
            if(visited[i])continue;
            dfs1(i,totalCompo);
            totalCompo++;
        }

        /*
        for( i = 0 ; i < totalCompo ; i++)
        {
            printf("Component %d -- \n\n",i+1);
            for( j = 0 ; j < compo[i].size() ; j++ )
            {
                cout<<compo[i][j]<<"  ";
            }
            puts("");
        }
        */

        for( i = 0 ; i < totalCompo ; i++ ){
            cycle(compo[i]);
        }

 //       cycle(compo[0]);
        cout<<"Case "<<cs++<<": "<<mxNode<<endl;
    }
    return 0;
}
