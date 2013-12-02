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

const int MX = 1000007;

int b[MX],s[MX];
int B , S ;
int main() {
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1 ;
    while(scanf("%d %d",&B,&S)==2) {
        if(B == 0 && S == 0) break;
        rep(i,B) b[i] = II ;
        rep(i,S) s[i] = II ;
        sort(b,b+B);
        int n = B - S ;
        if(B <= S) printf("Case %d: 0\n",cs++) ;
        else       printf("Case %d: %d %d\n" , cs++ , n , b[0]) ;
    }
}
