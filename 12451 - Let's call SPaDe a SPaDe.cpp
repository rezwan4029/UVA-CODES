/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 100 + 7 ;
const int INF = 1e8 + 7;

string Str;
int dp[MX][MX];
int len ;

int get(int v){
    if( v < 10 ) return 1 ;
    if( v < 100 ) return 2 ;
    return 3 ;
}
bool ok(int i , int j , int mLen ){
    string z = Str.substr(i,mLen);
    for( int x = i + mLen ; x <= j ; x += mLen ){
        if( z != Str.substr(x,mLen) ) return false ;
    }
    return true ;
}
int solve(int a , int b){
    if( a == b ) return 1 ;
    if( a > b ) return 0 ;
    int &ret = dp[a][b];
    if( ret != -1 ) return ret ;
    ret = INF ;
    for( int i = a ; i < b ; i++ ){
        ret = min( ret , solve(a,i)+solve(i+1,b) );
    }
    int range = ( b - a + 1 ) ;
    for( int matchLen = 1 ; matchLen <= ( range / 2 ) ; matchLen++ ){
        if( range % matchLen != 0 ) continue ;
        if( ok(a,b,matchLen) ) ret = min( ret , get(range/matchLen) + 2 + matchLen  );
    }
    return ret ;
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        cin >> Str;
        ms(dp,-1);
        len = Str.size() ;
        int Ans = solve(0,len-1);
        printf("%d\n",Ans);
    }
}
