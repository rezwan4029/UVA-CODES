#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>


using namespace std;

#define MM 100005

int n, m, caseno, cases;
vector <int> adj[MM];
bool visited[MM];

list <int> topo;

void call( int u ) {
    if( visited[u] ) return;
    visited[u] = true;
    for( int i = 0; i < adj[u].size(); i++ ) call( adj[u][i] );
    topo.push_front(u);
}

int main() {
    

    scanf("%d", &cases);
    while( cases-- ) {
        int i;
        scanf("%d %d", &n, &m);
        for( i = 0; i < m; i++ ) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
        }
        topo.clear();
        for( i = 0; i < n; i++ ) visited[i] = false;
        for( i = 0; i < n; i++ ) call(i);

        for( i = 0; i < n; i++ ) visited[i] = false;
        int cnt = 0;
        for( list <int> ::iterator l = topo.begin(); l != topo.end(); l++ ) if( !visited[ *l ] ) {
            call( *l );
            cnt++;
        }
        printf("Case %d: %d\n", ++caseno, cnt);
    
        for( i = 0; i < n; i++ ) adj[i].clear();
    }
    return 0;
}
/*
#include<iostream>
#include<vector>

using namespace std;


vector<int>V[100002];
int vis[100002];
vector<int>Order;
//vector<int>component;
void dfs1(int u)
{
    vis[u]=true;
    for(size_t i=0;i<V[u].size();i++)
    {
        if(!vis[ V[u][i] ]) dfs1(V[u][i]);
    }
    Order.push_back(u);

}
void dfs2(int u)
{
    vis[u]=true;
    //component. push_back( u ) ;

    for(size_t i=0;i<V[u].size();i++)
    {
        if(!vis[ V[u][i] ]) dfs2(V[u][i]);
    }
}
int main ()
{
int num,m,T,cs=1;
cin>>T;
    while (T--)
    {
        cin >> num>>m;
      int adj,u,v,i;

       memset(vis,0,sizeof vis);
       memset(V,0,sizeof V);
       Order.clear();

      while(m--)
      {
          cin>>u>>v;
          V[u].push_back(v);
      }
      for(i=1;i<=num;i++)
                        if(!vis[i])dfs1(i);
   //   for(size_t i=0;i<Order.size();i++)
    //  cout<<Order[i]<<" ";


     // printf("\n");

      memset(vis,false,sizeof vis);
    //  component.clear();
int cnt=0;
      for ( i = 0 ; i < num ;i++ )
      {
        u = Order[ num - 1 - i ] ;
        if ( ! vis[u] ) dfs2 (u) ,cnt++;
      }

   // for(size_t i=0;i<component.size();i++)
   //   cout<<component[i]<<" ";
   //   printf("\n");

    //  printf("Case %d: %d\n",cs++,cnt);
     printf("%d\n",cnt);

    }
    return 0;
}




/
