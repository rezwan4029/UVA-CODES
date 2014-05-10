/*
    Rezwan_4029 , AUST
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define makeUnique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
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


const int M = 1000007;

int dp[42][66][6][6][6][6][6][6];
int N ;
int solve(int pos , int mask , int m1 , int m2 , int m3 , int m4 , int m5 , int m6 ){
    if( pos == N  ) {
        if( (mask & (1<<0) ) and m1 ) return 0 ;
        if( (mask & (1<<1) ) and m2 ) return 0;
        if( (mask & (1<<2) ) and m3 ) return 0 ;
        if( (mask & (1<<3) ) and m4 ) return 0 ;
        if( (mask & (1<<4) ) and m5 ) return 0 ;
        if( (mask & (1<<5) ) and m6 ) return 0 ;
        return 1 ;
    }
    int &ret = dp[pos][mask][m1][m2][m3][m4][m5][m6];
    if( ret != -1 ) return ret ;
    ret = 0 ;
    for( int i = 1 ; i <= 6 ; i++ ){
        int x1 = ( m1 * 10 + i ) % 1 ;
        int x2 = ( m2 * 10 + i ) % 2 ;
        int x3 = ( m3 * 10 + i ) % 3 ;
        int x4 = ( m4 * 10 + i ) % 4 ;
        int x5 = ( m5 * 10 + i ) % 5 ;
        int x6 = ( m6 * 10 + i ) % 6 ;

        ret += solve( pos+ 1 , ( mask|1<<(i-1) ) , x1 , x2 , x3 , x4 , x5 , x6 );
        ret %= M ;
    }
    return ret ;
}

int A[] = {0,6,10,33,120,482,2105,9476,44348,211097,19369,967626,364709,62612,634177,576187,751629,983051,866460,769501,454602,699208,521190,377670,798034,381127,131716,853137,531126,906635,49193,784486,759570,417710,570525,825776,17000,10798,297155,976859,86929};
int main(){
#ifdef LOCAL
    //FI ;
#endif
    //FO ;

    int test ; read( test );
    For(cs,test){
        //ms(dp,-1);
        read( N );
        //int ans = solve(0,0,0,0,0,0,0,0);
        printf("%d\n",A[N]);
    }
}
