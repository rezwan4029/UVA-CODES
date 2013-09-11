#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define sz 205
vector<int>edges[sz];
int LeftMatch[sz], RightMatch[sz];
int N, M ;
int a[sz],b[sz];
bool visited[sz];

void clear()
{
     rep(i,201) edges[i].clear() , LeftMatch[i] = RightMatch[i] = -1 ;
}
void input()
{
     cin >> N ;
     rep(i,N) cin >> a[i];
     cin >> M ;
     rep(i,M) cin >> b[i];
}
void makeGraph()
{
     rep(i,N) rep(j,M) if( b[j] == 0 || ( a[i] != 0 && b[j] % a[i] == 0 )) edges[i].push_back( j + N );
}

bool match(int u)
{
     rep(i,edges[u].size())
     {
         int v = edges[u][i];
         
         if( visited[v] ) continue ;
         
         visited[v] = true;
         
         if( RightMatch[v] == - 1 || match(RightMatch[v]) == true)
         {
             RightMatch[v] = u;
             LeftMatch[u] = v ;
             return true;
         }
     }
     return false ;
}
int bipartiteMatch()
{
   int matching = 0 ;
   while(true)
   {
     memset(visited, false,sizeof visited);
     bool foundMatch = false ;
     rep(i,N)
     {
       if( LeftMatch[i] != -1) continue;
       if( match(i) ) foundMatch = true , matching++ ;
     }
     if( foundMatch == false ) break;
   }  
   return matching ;
}
int main()
{
    int t , cs =1 ;
 
    scanf("%d",&t);
    while(t--)
    {
      clear();
      input();
      makeGraph();
      int ans = bipartiteMatch();
      printf("Case %d: %d\n",cs++,ans);
    }
    return 0 ;
}
