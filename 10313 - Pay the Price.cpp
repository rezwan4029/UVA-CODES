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

const int MX = 307 ;
const int INF = 1e8 + 7;
int Sum , L1 , L2 ;
Long dp1[MX];
Long dp2[MX][MX];
int Coins[MX];
int Idx ;
Long toInt(string s){
    Long r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}
vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}
char Str[MX];

void Init(){
    vector<string>ret = Split(Str);
    Idx = ret.size() ;
    if( Idx == 1 ){
        Sum = toInt( ret[0] );
    }
    else if( Idx == 2 ){
         Sum = toInt( ret[0] );
         L1  = toInt( ret[1] );

    } else {
         Sum = toInt( ret[0] );
         L1  = toInt( ret[1] );
         L2  = toInt( ret[2] );
    }
}

void pre(){
    For(i,MX-7) Coins[i] = i ;
    ms(dp1,0);
    dp1[0] = 1 ;
    for( int i = 1 ; i <= MX-7 ; i++ )
        for( int j = 0 ; j + Coins[i] < MX ; j++ )
            if( dp1[j] ) dp1[ j + Coins[i]  ] += dp1[j];

    ms(dp2,0);
    dp2[0][0] = 1 ;
    for( int s = 0 ; s <= MX - 7 ; s++ ){
        for( int j = 1 ; j <= MX - 7 ; j++ ){
            dp2[s][j] += dp2[s][j-1];
            if( s - Coins[j] >= 0 )
                dp2[s][j] += dp2[ s - Coins[j] ][ j ];
        }
    }
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    pre();
    while( gets(Str) ){
        Init();
        if( Idx == 1 ) printf("%lld\n",dp1[Sum]);
        else if( Idx == 2 ){
            L1 = min(L1,300);
            printf("%lld\n",dp2[Sum][L1]);
        }else {
             L1 = min(L1,300);
             L2 = min(L2,300);
             printf("%lld\n",dp2[Sum][L2] - dp2[Sum][L1-1]);
        }
    }
}
