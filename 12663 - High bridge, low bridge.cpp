/*
    Royal_Flush , AUST
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

const int MAX_N = int (1e5) + 7;


typedef pair <ll, ll> pii;

ll n, m, k;
ll h [MAX_N], bit [MAX_N];
vector <pii> v;

inline int add (ll idx, ll val) { for (; idx <= n; idx += (idx & -idx)) bit [idx] += val; }
inline int get (ll idx, ll &val) { for (val = 0LL; idx > 0LL; idx -= (idx & -idx)) val += bit [idx]; }

int main () {
#ifdef LOCAL
	freopen ("in.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
#endif
    int cs = 0;
    while (scanf("%lld %lld %lld",&n,&m,&k) != EOF ) {
        For (i, n) h [i] = LL ;
        sort (h + 1, h + n + 1);
        v.clear ();
        ms (bit,0);

        ll a, b;
        rep (i, m) {
            a = LL , b = LL ;
            v.pb (pii (a, b));
        }
        v.pb (pii (b, 0));

        forstl (i, v) {
            ll a = i -> first;
            ll b = i -> second;
            ll start = upper_bound (h + 1, h + n + 1, b) - h;
            ll end   = upper_bound (h + 1, h + n + 1, a) - h - 1;
            if (start <= end) { add (start, 1); add (end + 1, -1); }
        }

        ll cnt = 0LL;
        For (i, n) {
            ll ans;
            get (i, ans);
            if (ans >= k) ++cnt;
        }

        printf("Case %d: %lld\n", ++cs , cnt );
    }
	return 0;
}
