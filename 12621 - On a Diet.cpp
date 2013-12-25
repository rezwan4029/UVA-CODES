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
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const int MX = 507 ;
int dp[MX] , a[MX] ;
int main(){
    int test = II ;
    For(cs,test){
        int Sum = II ;
        int N = II ;
        Sum /= 10 ;
        int tot = 0 ;
        rep(i,N){
            a[i] = II ;
            a[i] /= 10 ;
            tot += a[i];
        }
        if( Sum > tot ) {
            puts("NO SOLUTION");
            continue ;
        }
        ms(dp,0);
        dp[0] = 1 ;
        for( int i = 0 ; i < N ; i++ )
            for( int j = Sum ; j >= 0 ; j-- )
                if( dp[j] ) dp[ j+a[i] ] = 1 ;
        for( int i = Sum ; ; i++ ){
            if( dp[i] ) { printf("%d\n",i*10); break ; }
        }
    }
}
