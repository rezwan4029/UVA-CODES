/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi ;
typedef vector<ll>vl;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int n ;
    ll f[15];
    f[0] = 1 ;
    For(i,12) f[i] = i * f[i-1];
    int Cnt[12] ;
    while( scanf("%d",&n) && n ){
        int a[15] ;
        ms(Cnt,0);
        rep(i,n) {
            a[i] = II ;
            Cnt[ a[i] ]++;
        }
        ll ans = 0 ;
        rep(i,10){
            if( !Cnt[i] ) continue ;
            ll sum = 1 ;
            rep(j,10){
                if( !Cnt[j] ) continue ;
                if( i == j ) sum *= f[ Cnt[j] - 1 ];
                else sum *= f[ Cnt[j] ];
            }
            ans += i * f[ n - 1]/ sum ;
        }
        ll RES = 0 ;

        rep(i,n) RES = RES * 10 + ans ;

        printf("%lld\n",RES);
    }
}
