#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<int>E[50];
int ret ,tl;
int d[50];
bool Vis[50];
void bfs( int src)
{
    memset(Vis,false,sizeof Vis);
    queue<int>q;
    q.push(src);
    d[src] = 0;
    Vis[src] = true;
    while(!q.empty())
    {
       int u = q.front() ; q.pop();
       for( int i = 0 ; i < E[u].size(); i++ )
       {
            int v = E[u][i];
            if(Vis[v])continue;
            Vis[v] =true;
            d[v] = d[u]+1;
            q.push(v);
            if(d[v] <= tl)ret++;
       }
    }
}

int main()
{
   int edges ,cs = 1;
   map<int,int>m;
   while( cin >> edges )
   {
      if( !edges ) break ;
      m.clear();
      int id = 1 ;
      for( int i = 0 ; i < edges ; i++ ){
           int u,v ;
           cin >> u >> v;
           if( !m[u]) m[u] = id++;
           if( !m[v]) m[v] = id++;
           E[m[u]].push_back(m[v]);
           E[m[v]].push_back(m[u]);
      }
      int src ;
      while( scanf("%d %d",&src,&tl))
      {
             if( src == 0 && tl == 0 ) break;
             ret = 0 ;
             bfs(m[src]);
             printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs++,id-2-ret,src,tl);
      }
      for( int i = 0 ; i < id ; i++ ) E[i].clear();
   }
}
