/*
  Rezwan_4029
  AUST 25 th batch
  algo : Bridges 
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 10001

int N, counter, seen[MAXN], low[MAXN];
vector<int> adj[MAXN];
vector< pair<int,int> >Critical ;

void dfs(int x, int parent)
{
    low[x] = seen[x] = ++counter;

    for (int i = 0 ; i < adj[x].size() ; i++) 
    {
        int y = adj[x][i];
        if (y == parent) continue;
        if (seen[y] == 0) 
        {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] == seen[y]) 
            {
                //printf("Edge (%d, %d) is a bridge.\n", x, y);
                Critical.push_back(make_pair(min(x,y),max(x,y)));
            }
        } 
        else 
        {
            low[x] = min(low[x], seen[y]);
        }
    }
}

void clear()
{
     for( int i = 0 ; i < N ; i++ )
     {
          seen[i] = 0 ;
          adj[i].clear();
     }
     counter = 0 ;
     Critical.clear();
}
int main()
{
    while( cin >> N  )
    {
     int i, x, y, M;
     
     clear();
     for (i = 0; i < N; i++) {
        scanf("%d (%d)",&x,&M);
        for( int j = 0 ; j < M ; j++ ){
             cin >> y ;
             adj[x].push_back(y);
        }
     }
     for (x = 0; x < N; x++)
         if (seen[x] == 0) dfs(x, -1);
    
     printf("%d critical links\n",Critical.size());
     sort(Critical.begin(),Critical.end());
     for( int i = 0 ; i < Critical.size() ; i++ ) 
          printf("%d - %d\n",Critical[i].first,Critical[i].second);
      printf("\n");
     }
}
