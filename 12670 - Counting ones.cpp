/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

ull dp[55][2][2][55];
bool V[55][2][2][55] ;

string i2b(ll a) { string str = ""; do {str += (a&1)+'0';a >>= 1;}while(a);reverse(str.begin(),str.end()); return str; }

string Str ;
int N ;

ull solve(int pos , bool hasSmall , bool start , int countOne )
{
       if(pos == N) return countOne;
       ull &ret = dp[ pos ][ hasSmall ][ start ][ countOne ];
       if( V[ pos ][ hasSmall ][ start ][ countOne ]) return ret;
       V[ pos ][ hasSmall ][ start ][ countOne ] = true ;
       int lim = hasSmall ? 1 : Str[pos] - '0'; ret = 0;
       if(start) {
              For(i,lim) ret += solve( pos + 1 , hasSmall || ( i < lim ) , false , countOne + ( i == 1) ); // placing 1
              ret += solve( pos + 1 , true , true , 0 );
       }
       else {
              forab(i,0,lim) ret += solve( pos + 1 , hasSmall || ( i < lim ) , false , countOne + (i == 1) );
       }
       return ret;
}

ull calc(ull a , ull b ) {
    Str = i2b(b);
    N = Str.size();
    ms(V,false);
    ull ans = solve(0,false,true,0);
    Str = i2b(a-1);
    N = Str.size();
    ms(V,false);
    ans -= solve(0,false,true,0);
    return ans;
}

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    ull a , b ;
    while( scanf("%llu %llu",&a,&b) != EOF ){
        ull ret = calc(a,b);
        printf("%llu\n",ret);
    }
}
