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

struct team {
    int time, id, prob;
    team () {}
    team (int _time, int _id, string _prob) {
        time = _time;
        id = _id;
        prob = _prob [0] - 'A';    }
};

bool check [102][15];
int wt [15], wid [15];
vector <team> v;

int main () {
#ifdef Local
	freopen ("in.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
#endif
    int n, t, m;
    while (scanf("%d %d %d",&n,&t,&m) != EOF ) {
        ms (check,0);
        v.clear ();
        ms (wt, -1);
        ms (wid, -1);
        rep (i, m) {
            int time, id;
            string prob, reply;

            cin >> time >> id >> prob >> reply;
            if (reply == "No" || check [id][prob [0] - 'A']) continue;
            check [id][prob [0] - 'A'] = true;
            v.pb (team (time, id, prob));
        }

        forstl (i, v) {
            wt [i -> prob] = i -> time;
            wid [i -> prob] = i -> id;
        }

        rep (i, n) {
            cout << char (i + 'A');
            if (wt [i] == -1) printf(" -");
            else printf(" %d",wt[i]);

            if (wid [i] == -1) printf(" -");
            else printf(" %d",wid[i]);
            puts("");
        }
    }
	return 0;
}
