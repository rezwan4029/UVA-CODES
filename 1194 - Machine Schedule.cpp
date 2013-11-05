/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define sz 505
vector<int>edges[sz];
int LeftMatch[sz], RightMatch[sz];
int N, M ;
int a[sz],b[sz];
bool visited[sz];

void clear()
{
     rep(i,sz) edges[i].clear() , LeftMatch[i] = RightMatch[i] = -1 ;
}
void input()
{
     M = II ;
     int J = II ;
     rep(i,J){
        int id = II , x = II , y = II ;
        a[i] = x - 1 ;
        b[i] = y - 1 ;
     }
     M = J ;
}
void makeGraph()
{
     rep(i,M){
        edges[ a[i] ].pb(  b[i] );
     }
}

bool match(int u)
{
     forstl(it,edges[u])
     {
         int v = *it;

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
   rep(i,N){
       memset(visited, false,sizeof visited);
       if( match(i) ) matching++ ;
     }
   return matching ;
}
int main()
{
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif

    while(scanf("%d",&N) &&N )
    {
      clear();
      input();
      makeGraph();
      int ans = bipartiteMatch();
      printf("%d\n",ans);
    }
    return 0 ;
}
