/*
    Rezwan_4029 , AUST
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

#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
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
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

Long gcd (Long a, Long b, Long &x , Long &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	Long x1, y1;
	Long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (Long a, Long b, Long c, Long & x0, Long & y0, Long & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

void shift_solution (Long & x, Long & y, Long a, Long b, Long cnt) {
	x += cnt * b;
	y -= cnt * a;
}

Long find_all_solutions (Long a, Long b, Long c, Long minx, Long maxx, Long miny, Long maxy) {
	Long x, y, g;
	if (! find_any_solution (a, b, c, x, y, g)) return 0;
	a /= g;  b /= g;
	Long sign_a = a > 0 ? +1 : -1;
	Long sign_b = b > 0 ? +1 : -1;
	shift_solution (x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution (x, y, a, b, sign_b);
	if (x > maxx) return 0;
	Long lx1 = x;
	shift_solution (x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution (x, y, a, b, -sign_b);
	Long rx1 = x;
	shift_solution (x, y, a, b, - (miny - y) / a);
	if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
	if (y > maxy) return 0;
	Long lx2 = x;
	shift_solution (x, y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shift_solution (x, y, a, b, sign_a);
	Long rx2 = x;
	if (lx2 > rx2) swap (lx2, rx2);
	Long lx = max (lx1, lx2);
	Long rx = min (rx1, rx2);
	return (rx - lx) / abs(b) + 1;
}
long brute( long a , long b , long c , long p ){
    map<long,bool>has;
    for( int i = 0 ; i * c <= p ; i++ ) has[ i * c ] = 1 ;
    long ans = 0 ;
    for( int i = 0 ; a * i <= p ; i++ ){
        for( int j = 0 ; p - a*i - b*j >= 0 ; j++ ){
                if( has [ p - a*i - b*j ] ) ans++;
        }
    }
    return ans ;
}
int main() {
   // FI;
    int test = II ;
    For(cs,test){
        Long a , b , c , p ;
        read(a) , read(b) , read(c) , read(p);
       // __( brute(a,b,c,p) );
        Long g = __gcd(__gcd(a,b),c);
        a /= g , b /= g , c /= g ;
        printf("Case %d: ",cs);
        if( p % g != 0 ){
            printf("0\n");
            continue ;
        }
        p /= g ;
        // ax + by + cz = p
        // ax + by = ( p - cz )
        // ax + by = q  ; [ q = p - cz ]
        Long z = 0 , Ans = 0 ;
        while( true ) {
            Long q = p - c * z ;
            if( q < 0 ) break ;
            Ans += find_all_solutions(a,b,q,0,p,0,p);
            z++;
        }
        printf("%lld\n",Ans);
    }
}
