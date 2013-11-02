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
#define pi acos(0.0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define sz 501
vi edges[sz];
int LeftMatch[sz], RightMatch[sz];
int N ;
struct taxi{
    int a,b,c,d,Time;
    taxi(int _a , int _b , int _c , int _d , int _T){
        a = _a ;
        b = _b ;
        c = _c ;
        d = _d ;
        Time = _T;
    }
    taxi(){}
}Taxi[sz];

bool visited[sz];


bool valid(int i , int j ) {
    int t1 = Taxi[i].Time;
    int t2 = Taxi[j].Time;
    int d1 = abs( Taxi[i].a - Taxi[i].c ) + abs(  Taxi[i].b - Taxi[i].d );
    int d2 = abs( Taxi[i].c - Taxi[j].a ) + abs(  Taxi[i].d - Taxi[j].b );
    return ( (t1+d1+d2) < t2 ) ;
}

void clear()
{
     rep(i,N) edges[i].clear() , LeftMatch[i] = RightMatch[i] = -1 ;
}

void input()
{
    scanf("%d",&N);
    clear();
    rep(i,N)
    {
         int h , m , a , b , c , d ;
         scanf("%d:%d %d %d %d %d",&h,&m,&a,&b,&c,&d);
         int tt = h * 60 + m ;
         Taxi[i] = taxi(a,b,c,d,tt);
       //  cout << "-->>" << tt << endl;
     }
}
void makeGraph()
{
    rep(i,N){
        rep(j,N) {
            if( i == j )continue;
            if(valid(i,j)) {
                edges[i].pb(j);
            }
        }
    }
}

bool match(int u)
{
     int size = edges[u].size();
     rep(i,size)
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
   rep(i,N){
     ms(visited, false);
     if( match(i) )  matching++ ;
     if(matching == N )break ;
   }
   return matching ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t , cs =1 ;
    scanf("%d",&t);
    while(t--){
      input();
      makeGraph();
      int ans = bipartiteMatch();
      printf("%d\n",N-ans);
    }
    return 0 ;
}
