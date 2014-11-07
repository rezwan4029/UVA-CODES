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
int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

//const int MX = 1e5 + 7 ;

char St[110], Tm[110];
vi TIME ;
vpii score ;
int getTime(char *pp){
    int h , m , s ;
    sscanf(pp,"%d:%d:%d",&h,&m,&s);
    return h * 3600 + m * 60 + s ;
}
int led[] = {6,2,5,5,4,5,6,3,7,6};

int getAns( int x ){
    if( x == 0 ) return led[x];
    int an = 0 ;
    while( x != 0 ) {
        int t = x % 10 ;
        x /= 10 ;
        an += led[t];
    }
    return an;
}
int main(){
   // FI ;
    int cs = 1 ;
    while( cin >> St >> Tm ){
        TIME.clear();
        score.clear();
        //score.pb( pii(0,0) );
        int home = 0 , away = 0 ;
        TIME.pb( getTime(Tm) );
        while( cin >> St >> Tm ){
            TIME.pb( getTime(Tm) );
            if( !strcmp(St,"END") ) {
                score.pb( mp(home,away) );
                break ;
            }
            score.pb( mp(home,away) );
            cin >> St ;
            int sc = II ;
            if( !strcmp(St,"home") ) home += sc ;
            else away += sc ;
        }
        int len = score.size();
        Long Ans =  0 ;
        rep(i,len){
            int a = getAns(  score[i].ff ) , b =  getAns( score[i].ss ) ;
            Long Tmp = TIME[i+1] - TIME[i];
            Ans += Tmp * Long( a + b );
        }
        printf("Case %d: %lld\n",cs++,Ans);
    }
}
