/*
    Rezwan_4029 , AUST
*/

#include <bits/stdc++.h>
#include <bits/stdtr1c++.h>

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
int K , A[5007];
vi Vlo[5007];
vi Vhi[5007];

bool solve1(){
   for( int q = 0 ; q < K ; q++ ){
        for( int i1 = Vlo[q].size() - 1 ; i1 >= 0 ; i1-- ){
            int s = Vlo[q][i1];
            if( q < s ){
                for( int i2 = 0 ; i2 < (int)Vlo[s].size() ; i2++ ) {
                    int p = Vlo[s][i2] ;
                    if( p < q and p < s ){
                        for( int i3 = Vlo[p].size() - 1 ; i3 >= 0 ; i3-- ) {
                            int r = Vlo[p][i3];
                            if( q > r ) break;
                            if( q < r and r < s ) return true ;
                         //   else break ;
                        }
                    }else break;
                }
            }else break ;
        }
   }
   return false ;
}
bool solve2(){
   for( int q = 0 ; q < K ; q++ ){
        for( int i1 = Vhi[q].size() - 1 ; i1 >= 0 ; i1-- ){
            int s = Vhi[q][i1];
            if( q < s ){
                for( int i2 = 0 ; i2 < (int)Vhi[s].size() ; i2++ ) {
                    int p = Vhi[s][i2] ;
                    if( p < q and p < s ){
                        for( int i3 = Vhi[p].size() - 1 ; i3 >= 0 ; i3-- ) {
                            int r = Vhi[p][i3];
                            if( q > r ) break ;
                            if( q < r and r < s ) return true ;
                          //  else break ;
                        }
                    }else break;
                }
            }else break ;
        }
   }
   return false ;
}
int main(){
    int T ; read(T);
    For(cs,T){
        read(K);
        rep(i,K) read(A[i]);
        rep(i,5001) Vlo[i].clear() , Vhi[i].clear();
        for( int i = 0 ; i < K ; i++ ){
            for( int j = 0 ; j < K ; j++ ){
                if( i == j ) continue ;
                if( A[j] > A[i] ) Vhi[i].pb( j );
                else if( A[j] < A[i] )Vlo[i].pb(j);
            }
        }
        bool Ok = solve1();
        if( Ok  == false ) Ok |= solve2();
        if( Ok ) puts("YES");
        else puts("NO");
    }
}
