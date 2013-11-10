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
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


int a[100002];

int main(){
    #ifdef LOCAL
     //  freopen ("in.txt", "r", stdin);
    #endif
    int n , g ;
    while ( scanf("%d %d",&n,&g) != EOF ) {
        int ans = 0, cnt = 0;
        rep (i, n) {
            int s, r;
            cin >> s >> r;
           if (s > r) ans += 3;
            else if (s == r) {
                if (g) { ans += 3; --g; }
                else ++ans;
            }
            else a [cnt++] = r - s;
        }

        n = cnt;
        sort (a, a + n);

        rep (i, n) {
            if (a [i] > g) break;
            if (a [i] == g) { ++ans; break; }
            ans += 3; g-= (a [i] + 1);
        }

        printf("%d\n",ans);
    }
}
