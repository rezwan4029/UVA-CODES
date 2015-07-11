/*
    Rezwan_4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; read(a); a;})
#define LL ({Long a; read(a); a;})
#define DD ({long double a; scanf("%lf", &a); a;})
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
typedef pair<long double,long double>pdd;
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
#define __1D(a,n) {rep(i,n) { if(i) printf(" ") ; cout << a[i] ; } cout << endl;}
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

const int INF = 1e7;

int Items, Items_Price[20], TotalMenus, Menus[20][11];
int MenuPrice[20], Needed[10];
int dp[20][11][11][11][11][11][11];
int Vis[20][11][11][11][11][11][11], True;

int solve(int pos, int i1, int i2 , int i3 , int i4, int i5, int i6){
    if( pos == TotalMenus ){
        if( i1 == Needed[0] and
            i2 == Needed[1] and
            i3 == Needed[2] and
            i4 == Needed[3] and
            i5 == Needed[4] and
            i6 == Needed[5])
            return 0 ;
        return INF;
    }
    int &ret = dp[pos][i1][i2][i3][i4][i5][i6];
    if( Vis[pos][i1][i2][i3][i4][i5][i6] == True ) return ret;
    Vis[pos][i1][i2][i3][i4][i5][i6] = True;
    ret = solve(pos+1, i1, i2, i3, i4, i5, i6);
    i1 += Menus[pos][0];
    i2 += Menus[pos][1];
    i3 += Menus[pos][2];
    i4 += Menus[pos][3];
    i5 += Menus[pos][4];
    i6 += Menus[pos][5];
    if( i1 <= Needed[0] and i2 <= Needed[1] and i3 <= Needed[2] and
        i4 <= Needed[3] and i5 <= Needed[4] and i6 <= Needed[5])
        ret = min( ret, solve(pos, i1, i2, i3, i4, i5, i6)+ MenuPrice[pos]);
    return ret;
}
int main(){
    //FI;
    while( scanf("%d",&Items) == 1 ){
        rep(i,Items) Items_Price[i] = II ;
        TotalMenus = II ;
        rep(i,TotalMenus){
            rep(j,Items) Menus[i][j] = II ;
            MenuPrice[i] = II;
        }
        rep(i,Items){
            Menus[TotalMenus][i] = 1;
            MenuPrice[TotalMenus] = Items_Price[i];
            TotalMenus++;
        }
        ms(Needed, 0);
        int Q = II ;
        while(Q--){
            True++;
            rep(i,Items) Needed[i] = II ;
            printf("%d\n",solve(0,0,0,0,0,0,0));
        }
    }
}
