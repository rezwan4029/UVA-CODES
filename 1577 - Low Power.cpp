// World Finals - 2013 prob - F
/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-9
#define INF 1<<30
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll a [ 100020 ] , n , k ;

int main(){
    //freopen("in.txt","r",stdin);
    while( scanf("%lld %lld",&n,&k) != EOF ){
        ll sz = 2 * n * k ;
        rep(i,sz) a[i] = LL ;
        sort(a,a+sz);
        ll lo = a[1]  - a[0]  ;
        ll hi = a[sz-1] - a[0]  ;
        ll ans = INF ;
        ll mid ;
        For(iter,30){
            mid = ( lo + hi ) / 2 ;
            ll Cnt = 0 , taken = 0 ;
            rep(i,sz - 1 ){
                if( (a[i+1] - a[i]) <= mid ){
                    Cnt++ , taken += 2 ;
                    i++;
                }
                else{
                    taken++ ;
                }

                if( (taken > Cnt * 2 * k) || Cnt == n ) break ;
            }
            if(Cnt == n ){
                ans = min( ans , mid );
                hi = mid - 1 ;
            }
            else lo = mid + 1 ;
        }
        printf("%lld\n",ans);
    }
}
