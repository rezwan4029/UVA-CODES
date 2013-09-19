/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll solve(ll n){
    if( n < 0 ) n *= -1 ;
    for(ll ret = 0 , i = 1 ; ; i++ ){
        ret += i ;
        if( ret >= n && ( (ret - n) % 2 == 0) ) return i ;
    }
}

int main(){
    int test = II ;
    while(test--){
            ll n = LL ;
            printf("%lld\n",solve(n));
            if(test) printf("\n");
    }
}
