/* in the name of ALLAH, most gracious, most merciful */

//{ ************[       Template       ]************
using namespace std;
//{ ************[      C headers       ]************
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ ************[     C++ headers      ]************
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
//{ ************[     Test Report 1    ]************
// #include <tr1/regex>
// #include <tr1/unordered_set>
// #include <tr1/unordered_map>
//}
//}
//{ ************[        Loops         ]************
#define forab(i, a, b)	for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof(b) i = (b); i >= (a); --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ ************[   Floating points    ]************
#define EPS				DBL_EPSILON
#define abs(x)			(((x) < 0) ? - (x) : (x))
#define zero(x)			(abs (x) < EPS)
#define equal(a,b)		(zero ((a) - (b)))
#define PI				2 * acos (0.0)
//}
//{ ************[        Macros        ]************
#define mem(a, i)		memset ((a), i, sizeof ((a)))
#define clr(a)			mem ((a), 0)
#define all(a)			(a).begin (), (a).end ()
#define pb				push_back

template <class T, class U> inline T max (T &a, U &b) { return a > b ? a : b; }
template <class T, class U> inline T min (T &a, U &b) { return a < b ? a : b; }
static struct _ { ios_base :: Init Init; _ () { cin.sync_with_stdio (false); cin.tie (false); } } _;
//}
//{ ************[  Typedefs && Consts  ]************
typedef long long int64;
typedef unsigned long long int64u;

const int MAX_N = int (1e6) + 7;
const int MOD   = int (1e9) + 7;
//}
//}

int k, best, start, pos, len;
string str, rev;
int idx [1008];
int dp [1008][1008];
char temp [10008];
bool seen [1008][1008];

void ok (int i, int j, int x) {
    if (x > 2 * k) return;
    if (idx [j] - idx [i] + 1 == best && start > idx [i]) {
        start = idx [i];
        return;
    } else if (idx [j] - idx [i] + 1 > best) {
        best = idx [j] - idx [i] + 1;
        start = idx [i];
    }
}

int cherry (int i, int j) {
    if (i >= j || i == len || j == len) {
        ok (i, j, 0);
        return 0;
    }
    int &ret = dp [i][j];
    if (seen [i][j]) return ret;
    seen [i][j] = 1;
    ret = cherry (i + 1, j - 1) + 2 * (str [i] != str [j]);
    ok (i, j, ret);
    return ret;
}

int main () {
#ifdef LOCAL
	freopen ("in.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
#endif
    int cs = 0;
    while (cin >> k) {
        getline (cin, str);
        getline (cin, str);

        int tot = 0;
        len = str.size ();
        rep (i, len) {
            if (isalpha (str [i])) {
                temp [tot] = tolower (str [i]);
                idx [tot++] = i + 1;
            }
        }
        temp [tot] = 0;
        str = string (temp);

        len = str.size ();
        best = -1;
        start = len;
        clr (seen);
        rep (i, len) rep (j, len) cherry (i, j);
        cout << "Case " << ++cs << ": " << best << " " << start << endl;
    }
	return 0;
}
