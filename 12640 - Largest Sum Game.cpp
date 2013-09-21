/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with(0);cin.tie(0);
#define pb push_back
#define INF 1<<30
#define all(x) (x.begin(),x.end() )
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll toInt(string s){
    ll r ;
    istringstream ( s ) >> r;
    return r ;
}

vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

vector<ll>aa;
vector<string>a;
ll dp[100007];
int N ;
string Str ;
int main(){
    while(getline(cin,Str)){
        aa.clear() , a.clear() ;
        a = ( Split(Str) ) ;
        N = a.size() ;
        rep(i,N) aa.pb(toInt(a[i])) ;

        //rep(i,N) cout << aa[i] << " "; cout << endl;
        //cout << toInt("-1") << endl;
        dp[0] = 0 ;
        ll ans = 0 ;
        rep(i,N){
            dp[i+1] = 0 ;
            dp[i+1] = max(dp[i] + aa[i] , aa[i] );
            ans = max( ans , dp[i+1] );
        }
        printf("%lld\n",ans);

    }
}
