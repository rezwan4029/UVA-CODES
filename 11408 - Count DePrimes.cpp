/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanPlacef("%d", &a); a;})
#define LL  ({ll  a; scanPlacef("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

#define SZ 5000007

int dp[SZ];
bool isPrime[SZ];

void sieve(){
        ms(isPrime,true);
        isPrime[0] = isPrime[1] = false ;
        for(int i = 2 ; i < SZ ; i++ ){
            if( isPrime[i] ){
                dp[i] += i ;
                for(int j = i * 2 ; j < SZ ; j += i ){
                    isPrime[j] = false ;
                    dp[j] += i ;
                }
            }
        }
}
int main(){
    sieve();
    for(int i = 2 ; i < SZ ; i++ ){
        if( isPrime[ dp[i] ] ) dp[i] = dp[i-1] + 1 ;
        else dp[i] = dp[i-1];
    }
    int a , b ;
    while( scanf("%d",&a) && a ){
        scanf("%d",&b);
        printf("%d\n",dp[b]-dp[a-1]);
    }
}
