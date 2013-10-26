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

ll Hex2Int(string s){
    ll x ;
    std::stringstream ss;
    ss << std::hex << s;
    ss >> x;
    return x;
}
ll toInt(string s){
    ll r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}
string toString(ll number){
    stringstream ss;
    ss << number;
    return ss.str();
}

int main() {
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        int  N = II ;
        int b1 = __builtin_popcount(N);
        int b2 = __builtin_popcount( Hex2Int( toString(N) )  );
        printf("%d %d\n",b1,b2);
    }
}
