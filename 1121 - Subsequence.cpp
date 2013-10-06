/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define INF 1<<29
#define pi 2*acos(0.0)
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const int SZ = int (1e5) + 7;

ll n, s, a [SZ] ;

int main () {
	//freopen ("in.txt", "r", stdin);
    while(scanf("%lld %lld",&n,&s) != EOF){
        rep(i,n) a[i] = LL ;
        For(i,n) a[i] = a[i] + a[i-1];
        ll j = 0 ;
        ll MIN = INF ;
        rep(i,n){
            while( j <= i && (a[i] - a[j] >= s) ){
                     MIN = min( MIN , i - j  );
                     j++;
            }
        }
        if( MIN == INF ) MIN = 0 ;
        printf("%lld\n",MIN);
    }
	return 0;
}
