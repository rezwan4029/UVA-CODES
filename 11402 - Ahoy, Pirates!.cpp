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

#define lft at<<1
#define ryt at<<1|1
enum{ CLR = 0 , ZERO  , ONE , FLIP};
const int MX = 1024000 + 7 ;
const int INF = 1e8 + 7;
int N , Q , A[MX];
char str[60];
int T[MX<<2] , lazy[MX<<2];

void build(int at , int l , int r ){
    lazy[at] = CLR ;
    if( l == r ) {
        T[at] = A[l];
        return ;
    }
    int mid = (l+r) >> 1 ;
    build(lft,l,mid);
    build(ryt,mid+1,r);
    T[at] = T[lft] + T[ryt];
}
int doFlip(int x) {
    if( x == ONE ) return ZERO ;
    if( x == ZERO ) return ONE ;
    if( x == FLIP ) return CLR ;
    return FLIP ;
}
void propagate(int at , int x , int y){
    if( lazy[at] == CLR ) return ;
    if( lazy[at] == ONE ) {
        T[at] = y - x + 1 ;
    }
    else if( lazy[at] == ZERO ) {
        T[at] = 0;
    }
    else if( lazy[at] == FLIP ) {
        T[at] = ( y - x + 1 ) - T[at];
    }
    if( x != y ) {
        if( lazy[at] == ONE || lazy[at] == ZERO ) {
            lazy[lft] = lazy[ryt] = lazy[at];
        } else {
            lazy[lft] = doFlip( lazy[lft] );
            lazy[ryt] = doFlip( lazy[ryt] );
        }
    }
    lazy[at] = CLR ;
}
int Query(int at , int l , int r , int x , int y ){

    if( lazy[at] != CLR ) propagate(at,l,r);

    if( l > y || x > r ) return 0 ;

    if( l >= x && r <= y ) return T[at];
    int mid = (l+r) >> 1 ;
    int q1 = Query(lft,l,mid,x,y);
    int q2 = Query(ryt,mid+1,r,x,y);
    return q1 + q2 ;
}
/* Set all the values to 1 */
void update1(int at , int l , int r , int x , int y ){

    if( lazy[at] != CLR ) propagate(at,l,r);

    if( l > y || x > r ) return ;

    if( l >= x && r <= y ) {
        T[at] = r - l + 1 ;
        lazy[lft] = lazy[ryt] = ONE ;
        return ;
    }
    int mid = (l+r) >> 1 ;
    update1(lft,l,mid,x,y);
    update1(ryt,mid+1,r,x,y);
    T[at] = T[lft] + T[ryt];
}
/* Set all the values to 0 */
void update2(int at , int l , int r , int x , int y ){

    if( lazy[at] != CLR ) propagate(at,l,r);

    if( l > y || x > r ) return ;

    if( l >= x && r <= y ) {
        T[at] = 0 ;
        lazy[lft] = lazy[ryt] = ZERO ;
        return ;
    }
    int mid = (l+r) >> 1 ;
    update2(lft,l,mid,x,y);
    update2(ryt,mid+1,r,x,y);
    T[at] = T[lft] + T[ryt];
}
/* flip all the all values in range */
void update3(int at , int l , int r , int x , int y ){

    if( lazy[at] != CLR ) propagate(at,l,r);

    if( l > y || x > r ) return ;

    if( l >= x && r <= y ) {
        T[at] = ( r - l + 1 ) - T[at] ;
        lazy[lft] = doFlip( lazy[lft] );
        lazy[ryt] = doFlip( lazy[ryt] );
        return ;
    }
    int mid = (l+r) >> 1 ;
    update3(lft,l,mid,x,y);
    update3(ryt,mid+1,r,x,y);
    T[at] = T[lft] + T[ryt];
}
int main () {
#ifdef LOCAL
	FI ;
#endif
    int test ; read(test);
    For(cs,test) {
        N = 0 ;
        ms(A,0);
        int Specs ; read(Specs);
        while( Specs-- ) {
            int t ; read(t) ;
            scanf("%s",str);
            int len = strlen( str );
            rep(i,t) rep(j,len) A[N++] = str[j] - '0' ;
        }
        //__(N) ;rep(i,N) cout << A[i] ; puts("");
        build(1,0,N-1);
        read(Q) ;
        int q = 0 ;
        printf("Case %d:\n",cs);
        while(Q--){
            int x , y ;
            scanf("%s",&str); read(x) , read(y) ;
            //__(str[0],x,y);
            //int x , y ; read(x) , read(y);
            if( str[0] == 'I' ) update3(1,0,N-1,x,y) ;
            else if( str[0] == 'F' ) update1(1,0,N-1,x,y) ;
            else if( str[0] == 'E' ) update2(1,0,N-1,x,y) ;
            else  printf("Q%d: %d\n",++q,Query(1,0,N-1,x,y));
        }
    }
}
