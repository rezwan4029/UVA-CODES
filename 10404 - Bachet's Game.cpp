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

const int MX = 1000010 ;

int N , M ;
bool dp[MX];
int moves[12];

int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
    while( scanf("%d",&M) == 1 ){
        N = II ;
        ms(dp,false);
        rep(i,N) moves[i] = II ;
        For(j,M){
            rep(i,N) if( j - moves[i] >= 0 && !dp[ j - moves[i] ] ){
                dp[j] = true;
                break;
            }
        }
        printf("%s wins\n",dp[M]? "Stan" : "Ollie" );
    }
}
