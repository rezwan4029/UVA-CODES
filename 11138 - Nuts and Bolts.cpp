/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include <queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

#define sz 505
vector<int>edges[sz];
int LeftMatch[sz], RightMatch[sz];
int N, M ;
int a[sz],b[sz];
bool visited[sz];
int grid[sz][sz];

void clear()
{
     rep(i,501) edges[i].clear() , LeftMatch[i] = RightMatch[i] = -1 ;
}
void input()
{
     cin >> N  >> M;
     rep(i,N) rep(j,M) cin >> grid[i][j];
}
void makeGraph()
{
     rep(i,N) rep(j,M) if( grid[i][j] ) edges[i].push_back( j  );
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
      printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cs++,ans);
    }
    return 0 ;
}

