/*
    Rezwan_4029
    AUST , CSE-25
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

#define mod 1000000

int dp[102][102];

int solve(int n , int k){
    if(k == 1 ) return 1 ;
    int &ret = dp[n][k];
    if(ret != -1 )return ret ;
    ret = 0 ;
    forab(i,0,n){
        ret = ret + solve(i,k-1) ;
    }
    return ret %= mod ;
}

int main(){
    int n , k ;
    ms(dp,-1);
    while(scanf("%d %d",&n,&k)){
        if(n == 0 && k == 0 ) break ;
        int ret = solve(n,k);
        printf("%d\n",ret%mod);
    }
}
