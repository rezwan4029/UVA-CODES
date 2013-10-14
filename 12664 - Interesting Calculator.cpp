/*
    Royal_Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
//#define INF 1<<30
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

ll x, y, dp [MAX_N], move [MAX_N];
ll cost [3][10];

#define INF 100000000000000

void solve () {
    ms (dp,0);
    ms (move,0);

    dp [0] = cost [2][0];
    move [0] = 1;
    For (i, y) {
        if (i == x) continue;

        // add a digit
        dp [i] = dp [i / 10] + cost [0][i % 10];
        move [i] = move [i / 10] + 1;

        // sum
        rep (j, 10) if (i - j >= 0) {
            if (dp [i] > dp [i - j] + cost [1][j]) {
                dp [i] = dp [i - j] + cost [1][j];
                move [i] = move [i - j] + 1;
            } else if (dp [i] == dp [i - j] + cost [1][j]) move [i] = min (move [i], move [i - j] + 1);
        }

        // mul
        forab (j, 2, 9) if (i % j == 0) {
            if (dp [i] > dp [i / j] + cost [2][j]) {
                dp [i] = dp [i / j] + cost [2][j];
                move [i] = move [i / j] + 1;
            } else if (dp [i] == dp [i / j] + cost [2][j]) move [i] = min (move [i], move [i / j] + 1);
        }
    }
}

int main () {
#ifdef LOCAL
	freopen ("in.txt", "r", stdin);
#endif
    int cs = 0;
    while (scanf("%lld %lld",&x,&y) != EOF ) {
        rep (i, 3) rep (j, 10) cost [i][j] = LL ;
        solve ();
        printf("Case %d: %lld %lld\n", ++cs , dp[y] , move[y] );
    }
	return 0;
}
