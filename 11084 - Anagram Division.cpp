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

ll dp[1050][10050];
bool Vis[1050][10050];
char s[12];
int d , n ;
ll solve(int mask , int mod){
    if( mask == (1<<n)-1 ){
        return mod == 0 ;
    }
    ll &ret = dp[mask][mod];
    if( Vis[mask][mod] )return ret ;
    Vis[mask][mod] = true ;
    ret = 0 ;
    rep(i,n){
        if(mask &(1<<i) ) continue ;
        int x = (  s[i] - '0'  + mod*10 ) % d ;
        ret += solve( mask|(1<<i) ,x );
    }
    return ret ;
}
int f[11] , Cnt[11] ;
int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    f[0] = 1 ;
    For(i,10) f[i] = i * f[i-1];
    int test = II ;
    For(cs,test){
        scanf("%s %d",&s,&d);
        n = strlen(s);
        ms(Vis,0) , ms(Cnt,0);
        rep(i,n) Cnt[ s[i] - '0' ]++;
        ll ret = solve(0,0);
        rep(i,10){
            if(Cnt[i]) ret /= f[ Cnt[i] ];
        }
        printf("%lld\n",ret);
    }
}
