/*
    rezwan_4029
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

vl PowerSet(vl a){
    int len = a.size();
    vl S;
    rep(mask,(1<<len)){
        ll sum = 0 ;
        rep(i,len){
            if(mask & (1<<i)) sum += a[i];
        }
        S.pb(sum);
    }
    return S;
}

int main(){
    int N ;
    ll Sum ;
    while( scanf("%d %lld",&N,&Sum) == 2){
        vl a, b;
        rep(i,N) {
            if( i < N/2 ) a.pb(II);
            else b.pb(II);
        }
        vl x = PowerSet(a);
        vl y = PowerSet(b);
        sort(all(y));
        ll ans = 0 ;
        forstl(i,x){
            ll v = Sum - *i ;
            int p = upper_bound(all(y), v) - y.begin();
            int q = lower_bound(all(y), v) - y.begin();
            ans += abs(p-q);
        }
        if( Sum == 0 ) ans--;
        printf("%lld\n",ans);
    }
}
