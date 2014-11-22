/*
   Team - icpc2014dhaka-36 , AUST_toothless
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair

#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

typedef vector<int>    vi;
typedef vector<Long>   vl;
typedef vector<string> vs;
typedef vector<pii>  vpii;
typedef set<int> si;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define __( args... ) { dbg , args ; cerr << endl; }

struct debugger {
    template< typename T > debugger & operator , ( const T &v ) {
        cerr << v << "\t" ;
        return *this;
    }
}dbg;
// Pair Print
template< class A , class B > ostream &operator << ( ostream &o, const pair<A,B> &p ) {
    return o<<"(" << p.ff << ", " << p.ss << ")" ;
}
//Vector Print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
//Set Print
template<class T> ostream& operator<<(ostream& o, const set<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
template<class T> inline void MAX( T &a , T b) { if (a < b ) a = b; }
template<class T> inline void MIN( T &a , T b) { if (a > b ) a = b; }

//Fast Reader
template< class T > inline bool read( T &x ) {
    int c = getchar() ;
    int sgn = 1;
    while( ~c && c < '0' || c > '9' ) {
        if( c == '-' )sgn = -1 ;
        c = getchar() ;
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = getchar() ) x = x * 10 + c - '0' ;
    x *= sgn ;
    return ~c ;
}
const int MX = 111;
const int INF = 1e8;
int N , M , fish[MX][MX];
int dp1[MX][MX][MX];
int dp2[MX][MX][MX];
int Vis1[MX][MX][MX];
int Vis2[MX][MX][MX];
int True;
int go1(int x , int y , int k){
    if( k == 0 ) return 0 ;
    if( x <= 0 or y <= 0 ) return -INF ;
    int &ret = dp1[x][y][k];
    if( Vis1[x][y][k] == True ) return ret ;
    Vis1[x][y][k] = True;
    ret = go1(x-1,y-1,k-1)+fish[x][y];
    MAX(ret , go1(x-1,y,k) );
    MAX(ret , go1(x,y-1,k) );
    go1(x,y,k-1);
    return ret;
}
int go2(int x , int y , int k){
    if( k == 0 ) return 0 ;
    if( x <= 0 or y <= 0 ) return +INF ;
    int &ret = dp2[x][y][k];
    if( Vis2[x][y][k] == True ) return ret ;
    Vis2[x][y][k] = True;
    ret = go2(x-1,y-1,k-1)+fish[x][y];
    MIN(ret , go2(x-1,y,k) );
    MIN(ret , go2(x,y-1,k) );
    go2(x,y,k-1);
    return ret;
}
int main(){
    //freopen("bin.txt","r",stdin);
    int T = II ;
    For(cs,T){
        N = II , M = II ;
        For(i,N) For(j,M) fish[i][j] = II ;
        True++;
        int Ans = 0 , K = 0 ;
        for( int k = 0 ; k * 2 <= min(N,M) ; k++ ) K++;
        go1(N,M,K);
        go2(N,M,K*2);
        rof(k,K)MAX( Ans , dp1[N][M][k] - dp2[N][M][k*2] );
        printf("%d\n",Ans);
    }
}
