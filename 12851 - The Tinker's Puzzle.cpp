/*
    AUST_toothless
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

double EPS = 1e-7;
int main() {
    //freopen("bin.txt","r",stdin);
    int T = II ;
    For(cs,T){
        double d = DD ,v = DD;
        v*= 282.;
        double a = 8.*pi*d;
        a /= 3.;
        double b = pi*d;
        b /= 3.;
        a = a - b;
        a = v/a;
        double r = sqrt(a);
        r *= 4.;
        printf("Case %d: %.3lf\n",cs,r+EPS);
    }
}
