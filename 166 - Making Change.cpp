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

const int MX = 1001  ;
const int INF = 1e7 + 7;

int coins[] = {5,10,20,50,100,200};
int freq[7];
int N = 6;
int Sum ;
int dp[7][MX+7];
bool V[7][MX+7];
int ShopKeeper[MX];
int Buyer[MX];

int solve1(int pos , int s){
    if( pos == N ) {
        if( s == 0 ) return 0 ;
        return INF ;
    }
    int &ret = dp[pos][s];
    if( V[pos][s] ) return ret ;
    V[pos][s] = true , ret = INF;
    if( s - coins[pos] >= 0 ) ret = solve1(pos,s - coins[pos])+1;
    ret = min( ret , solve1(pos+1,s) );
    return ret ;
}

int solve2(int pos , int s){
    if( pos == N ) {
        if( s == 0 ) return 0 ;
        return INF ;
    }
    int &ret = dp[pos][s];
    if( V[pos][s] ) return ret ;
    V[pos][s] = true , ret = INF;
    For(i,freq[pos]){
        int x = i * coins[pos];
        if( s - x >= 0 ) ret = min( ret , solve2(pos+1,s-x)+i ) ;
        else break ;
    }
    ret = min( ret , solve2(pos+1,s) );
    return ret ;
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w" , stdout);
    #endif
    rep(i,MX) ShopKeeper[i] = solve1(0,i);
   // rep(i,MX) cout << i << ":: "<< ShopKeeper[i] << endl ;
    while( true ){
        int s = 0 ;
        rep(i,N){
            freq[i] = II ;
            s += freq[i];
        }
        if( s == 0 ) break ;
        double v ; scanf("%lf",&v);
        Sum = (v * 100) + .5 ;
        ms(V,0);
        rep(i,MX) Buyer[i] = solve2(0,i);
       // puts("ok");
        //rep(i,MX) cout << i << ":: "<< Buyer[i] << endl ;
        int Ans = INF ;
        rep(i,MX){
            if( Sum + i < MX ) {
                Ans = min( Ans , Buyer[i+Sum] + ShopKeeper[i] );
            }else break ;
        }
        printf("%3d\n",Ans);
    }
}
