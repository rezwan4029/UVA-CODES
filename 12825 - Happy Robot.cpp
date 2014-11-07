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

int dx[]={1,0,-1,0};int dy[]={0,-1,0,1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int MX = 1005 ;

int Vis[MX][4] , dp[MX][4] , True ;
char str[MX];
int N ;
int MinX(int pos,int dir) {
    if( pos == N ) return 0 ;
    int &ret = dp[pos][dir];
    if( Vis[pos][dir] == True ) return ret;
    Vis[pos][dir] = True ;
    if( str[pos] == '?' ) {
        ret = MinX(pos+1,dir) + dx[dir];
        ret = min(ret , MinX(pos+1,(dir+1)%4));
        ret = min(ret , MinX(pos+1,(dir-1+4)%4));
    }
    else {
        if(str[pos] == 'F' ) ret = MinX(pos+1,dir) + dx[dir];
        else if(str[pos] == 'L' ) ret = MinX(pos+1,(dir-1+4)%4);
        else ret = MinX(pos+1,(dir+1)%4);
    }
    return ret ;
}
int MaxX(int pos,int dir) {
    if( pos == N ) return 0 ;
    int &ret = dp[pos][dir];
    if( Vis[pos][dir] == True ) return ret;
    Vis[pos][dir] = True ;
    if( str[pos] == '?' ) {
        ret = MaxX(pos+1,dir) + dx[dir];
        ret = max(ret , MaxX(pos+1,(dir+1)%4));
        ret = max(ret , MaxX(pos+1,(dir-1+4)%4));
    }
    else {
        if(str[pos] == 'F' ) ret = MaxX(pos+1,dir) + dx[dir];
        else if(str[pos] == 'L' ) ret = MaxX(pos+1,(dir-1+4)%4);
        else ret = MaxX(pos+1,(dir+1)%4);
    }
    return ret ;
}
int MinY(int pos,int dir) {
    if( pos == N ) return 0 ;
    int &ret = dp[pos][dir];
    if( Vis[pos][dir] == True ) return ret;
    Vis[pos][dir] = True ;
    if( str[pos] == '?' ) {
        ret = MinY(pos+1,dir) + dy[dir];
        ret = min(ret , MinY(pos+1,(dir+1)%4));
        ret = min(ret , MinY(pos+1,(dir-1+4)%4));
    }
    else {
        if(str[pos] == 'F' ) ret = MinY(pos+1,dir) + dy[dir];
        else if(str[pos] == 'L' ) ret = MinY(pos+1,(dir-1+4)%4);
        else ret = MinY(pos+1,(dir+1)%4);
    }
    return ret ;
}
int MaxY(int pos,int dir) {
    if( pos == N ) return 0 ;
    int &ret = dp[pos][dir];
    if( Vis[pos][dir] == True ) return ret;
    Vis[pos][dir] = True ;
    if( str[pos] == '?' ) {
        ret = MaxY(pos+1,dir) + dy[dir];
        ret = max(ret , MaxY(pos+1,(dir+1)%4));
        ret = max(ret , MaxY(pos+1,(dir-1+4)%4));
    }
    else {
        if(str[pos] == 'F' ) ret = MaxY(pos+1,dir) + dy[dir];
        else if(str[pos] == 'L' ) ret = MaxY(pos+1,(dir-1+4)%4);
        else ret = MaxY(pos+1,(dir+1)%4);
    }
    return ret ;
}
int main() {
    int cs = 1 ;
    while(scanf("%s",str)==1) {
        N = strlen(str);
        True++;
        int a = MinX(0,0);
        True++;
        int b = MaxX(0,0);
        True++;
        int c = MinY(0,0);
        True++;
        int d = MaxY(0,0);
        printf("Case %d: %d %d %d %d\n",cs++,a,b,c,d);
    }
}
