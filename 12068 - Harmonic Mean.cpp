/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
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

int a[11];

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int Set = II ;
    For(cs,Set){
        int N = II ;
        ll MUL = 1 ;
        rep(i,N) {
            a[i] = II ;
            MUL *= a[i] ;
        }
        ll deno = 0 ;
        rep(i,N){
            deno += ( MUL / a[i] );
        }
        ll num = MUL*N;
        ll g = __gcd(num,deno);
        num /= g ;
        deno /= g ;
        printf("Case %d: %lld/%lld\n",cs,num,deno);
    }
}
