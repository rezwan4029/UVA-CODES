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

int N ;
pll P[MX];
bool IsOk( pll a , pll b , pll c ){
    Long ab = (a.ff - b.ff) * (a.ff - b.ff) +  (a.ss - b.ss) * (a.ss - b.ss) ;
    Long bc = (c.ff - b.ff) * (c.ff - b.ff) +  (c.ss - b.ss) * (c.ss - b.ss) ;
    Long ac = (a.ff - c.ff) * (a.ff - c.ff) +  (a.ss - c.ss) * (a.ss - c.ss) ;
    if( ab == bc and ab != ac ) return true ;
    if( ab == ac and ab != bc ) return true ;
    if( ac == bc and ab != ac ) return true ;
    return false ;
}
bool collinear(pll p1, pll p2 , pll p3) {
    return (p1.ss - p3.ss) * (p2.ff - p3.ff) == (p2.ss - p3.ss) * (p1.ff - p3.ff);
}
bool Is_isosceles( pll a , pll b , pll c ){
    if( collinear(a,b,c) ) return false ;
    if( IsOk(a,b,c) ) return true ;
    return false ;
}
int main() {
   // FI;
    while( read(N) ){
        rep(i,N){
            P[i].ff = II ;
            P[i].ss = II ;
        }
        int Ans = 0 ;
        rep(i,N) forab(j,i+1,N-1) forab(k,j+1,N-1) Ans += Is_isosceles(P[i],P[j],P[k]) ;
        printf("%d\n",Ans);
    }
}
