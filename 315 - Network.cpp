#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <set>
#include  <deque>
#include <sstream>
#include <utility>
using namespace std;
#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define show_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
int cs = 1 ;
#define INF 10109999990
#define msn(a,n) memset(a,n,sizeof(a))
#define i64 long long
#define i64U unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define PB pop_back
#define mp make_pair
#define all(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795

#define pii pair< int ,int >
#define pll pair< i64 ,i64 >
#define psi pair< string , int >
#define vi  vector < int >
#define vs  vector < string >

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;} // string to int
vector<string>token( string a, string b )
{
    const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;
    vector<string>oot; while( *q ) { const char *e = q;while( *e && !count( b.begin(), b.end(),*e ) ) e++;
    oot.push_back( string( q, e ) );q = e; while( count( b.begin(),b.end(), *q ) ) q++;} return oot;
}

#define mx 105
int node ;

vi edges[mx];

int counter, seen[mx], low[mx];
int Critical ;
void dfs(int x, int parent)
{
    int kids = 0, art = 0;

    low[x] = seen[x] = ++counter;
    vi ::iterator it;
    forstl(it ,edges[x]) {
        int y = *it;
        if (y == parent) continue;
        if (seen[y] == 0) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            art |= (low[y] >= seen[x]);
            kids++;

        }
        else  low[x] = min(low[x], seen[y]);
    }

    if (parent == -1) art = (kids >= 2);
    if (art) Critical ++ ;
}


int main()
{
  char adj[1010];

  while( true )
  {
      node = II ;
      if( node == 0 )break;
      getchar();
      while( gets(adj))
      {
          vs tmp = token(adj," ");
          vs ::iterator x ;
          vi tempo ;
          forstl(x,tmp)tempo.pb( toInt( *x ) );
          if( tempo[0] == 0 )break;
          int sz = tempo.size();
          for(int i = 1 ; i< sz ; i++) {
              edges[ tempo[0] ].pb( tempo[i] ) ;
              edges[ tempo[i] ].pb( tempo[0] ) ;
          }
      }
      Critical = 0 ;
      for (int i = 1; i <= node; i++) if (seen[i] == 0) dfs(i, -1);
      for (int i = 0; i <= node; i++) {
          edges[ i ].clear();
          seen[ i ] = 0 ;
      }
      printf("%d\n",Critical);
  }
}
