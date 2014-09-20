/*
    rezwan4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

#define CS printf("Case #%d:",cs)

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print
template<class T> inline void MAX(T &a , T b){ if (a < b ) a = b;}
template<class T> inline void MIN(T &a , T b){ if (a > b ) a = b;}

//Fast Reader
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
const int MX = 1e5 + 7 ;
const int MD = 1e9 + 7 ;

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
    //FI;
    int M;
    bool f = false;
    while( cin >> N >>M  )
    {
        if(N==0&&M==0)return 0;

     int i, x, y;

     clear();
     for (i = 0; i < M; i++) {
             cin >> x>> y ;
             adj[x].push_back(y);
             adj[y].push_back(x);
     }
     for (x = 0; x < N; x++)
         if (seen[x] == 0) dfs(x, -1);

     printf("%d",Critical.size());
     sort(Critical.begin(),Critical.end());
     for( int i = 0 ; i < Critical.size() ; i++ )
          printf(" %d %d",Critical[i].first,Critical[i].second);
      printf("\n");
     }
}
