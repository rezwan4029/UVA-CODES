/*
    rezwan4029 , AUST
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; read(a); a;})
#define LL ({Long a; read(a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define CS printf("Case #%d:",cs)

#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int> psi;
typedef pair<Long,Long> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vpii;

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
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c <'0' || c > '9' ){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

#define MX 5050

const Long INF = 1e17 ;

struct NODE{
    Long v,Cap,Cost,RevInd;
    // This ind is necesery for multigraph to knw which edge is used to take flow
};
vector<NODE> Edge[MX];
Long nV,nE,P;
Long SRC,TNK;
// This PInd is neceserry for multigraph to knw which edge ind of parent is used to take flow
Long Par[MX],PInd[MX];
Long SD[MX];// Shortest path

void SetEdge( Long u,Long v,Long Cap,Long Cost ) {
       NODE U ={ v,Cap,Cost,Edge[v].size()};
       NODE V ={ u,0,-Cost,Edge[u].size()};
       Edge[u].push_back( U);
       Edge[v].push_back( V);
}

bool BFord() {
        Long i,u,k;
        for( i=SRC;i<=TNK;i++){
                Par[i] =-1;SD[i] =INF;
        }
        bool IsChange =true;
        SD[SRC] =0;
        while( IsChange ){
                IsChange =false;
                for( u=SRC;u<=TNK;u++){
                        for( i=0;i<(Long)Edge[u].size();i++){
                                if( !Edge[u][i].Cap) continue;
                                long v = Edge[u][i].v;
                                Long TD = SD[u] +Edge[u][i].Cost;
                                // relaxation
                                if( SD[v] > TD ){
                                        SD[v] = TD;Par[v] =u;PInd[v] =i;
                                        IsChange = true;
                                }
                        }
                }
        }
        return Par[TNK]!=-1;
}
Long FindVol( Long s,Long t) {
        Long Cap =Edge[ Par[t]][ PInd[t]].Cap;
        if( s==Par[t]) return Cap;
        else return min( Cap,FindVol( s,Par[t]));
}
Long AugmentPath( Long s,Long t,Long V) {
        if( s==t ) return 0;
        Long Cost =Edge[ Par[t]][PInd[t]].Cost*V;
        Edge[ Par[t]][ PInd[t]].Cap -=V;
        Edge[ t][ Edge[ Par[t]][PInd[t]].RevInd].Cap +=V;
        return Cost + AugmentPath( s,Par[t],V);
}
void MinCost( Long &Flow,Long &Cost) {
        Flow = Cost = 0;
        while( BFord()){
           Long V =FindVol( SRC,TNK );
           Flow +=V;
           Cost +=AugmentPath( SRC,TNK,V);
        }
}
Long Arr[MX][MX] , DataFlow , LinkCapacity ;
void Input(){
	For(i,nV) For(j,nV) Arr[i][j] = INF ;
	rep(i,nE){
		int u = II , v = II , w = II ;
		Arr[u][v] = Arr[v][u] = w ;
	}
	read(DataFlow);
	read(LinkCapacity);

	SRC = 0 ;
	TNK = nV + 1 ;
	SetEdge(0,1,DataFlow,0);
	SetEdge(nV,TNK,DataFlow,0);
	For(i,nV)For(j,nV){
		if( Arr[i][j] == INF ) continue;
		SetEdge(i,j,LinkCapacity,Arr[i][j]);
	}
}
int main(){
	//FI;
	while(scanf("%lld %lld",&nV,&nE) == 2){
		rep(i,MX-2) Edge[i].clear();
		Input();
		Long Flow, Cost ;
		MinCost(Flow,Cost);
		if(Flow >= DataFlow ) printf("%lld\n",Cost);
		else puts("Impossible.");
	}
}
