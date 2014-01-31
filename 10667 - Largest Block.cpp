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

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#ifdef LOCAL
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}
#endif
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

const int MX = 100 + 7 ;
int g[MX][MX] , N ;
int H[MX] ;
int Histogram() {
    stack<int>Stk;
    int Ans = 0 , pos = 0 , top , Area_With_Top ;
    while( pos < N ){
        if( Stk.empty() || H[ Stk.top() ] <= H[pos] ) Stk.push(pos++);
        else {
            top = Stk.top() ;
            Stk.pop();
            Area_With_Top = H[top] * ( Stk.empty() ? pos : pos - Stk.top() - 1 );
            Ans = max( Ans , Area_With_Top );
        }
    }
    while( !Stk.empty() ){
        top = Stk.top();
        Stk.pop();
        Area_With_Top = H[top] * ( Stk.empty() ? pos : pos - Stk.top() - 1 );
        Ans = max( Ans , Area_With_Top );
    }
    return Ans ;
}
int main(){
#ifdef LOCAL
    FI ;
#endif
    int T ; read(T);
    while( T-- ){
        read(N);
        ms(g,0);
        ms(H,0);
        rep(i,N) rep(j,N) g[i][j] = 1 ;
        int q ; read(q);
        while( q-- ){
            int x1 , y1 , x2 , y2 ;
            read(x1) , read(y1) , read(x2) , read(y2);
            x1--,x2--,y1--,y2--;
            forab(i,x1,x2) forab(j,y1,y2) g[i][j] = 0 ;
        }
        int Ans = 0 ;
        rep(i,N){
            rep(j,N) g[i][j] == 0 ? H[j] = 0 : H[j]++;
            MAX( Ans, Histogram() );
        }
        printf("%d\n",Ans);
    }
}
