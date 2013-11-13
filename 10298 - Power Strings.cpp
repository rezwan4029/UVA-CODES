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


int N ;
const int MX = 10000008;
char pat[MX];
int fail[MX];

int failureFunction () {
    fail[1] = 0 ;
    int i, shift = 0;
    for (i = 2; pat [i - 1]; ++i) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = fail [shift];
        if (pat [shift] == pat [i - 1]) ++shift;
        fail [i] = shift;
    }
    return i - 1;
}


int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif

    while( scanf("%s",&pat) ){
        if( pat[0] == '.' ) break ;
        failureFunction() ;
        N = strlen(pat);/*
        cout << pat << endl;
        for( int i =  1 ; i < N+1 ; i++ ) cout << fail[i] << "   ";
        cout << "\n---------\n";
*/
        int Ans = N  - fail[ N  ];
        printf("%d\n",N/Ans);
    }
}
/*
abcd
0   0   0   0
---------
1

aaaa
0   1   2   3
---------
4

ababab
0   0   1   2   3   4
---------
3

abcabc
0   0   0   1   2   3
---------
2

*/
