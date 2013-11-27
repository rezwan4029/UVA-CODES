/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
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

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define MX 200007
const ll inf = 1e12 + 7 ;

struct Node{
    ll st,en;
};

Node Block[MX];
int N ;

bool cmp(Node a,Node b){
    if( a.en == b.en ) return a.st < b.st;
    return a.en < b.en;
}

int doll()
{
    vl v ;
    sort(Block,Block+N,cmp);
    v.push_back(inf);
    int ans = 0;
    rep(i,N) {
        ll now = Block[i].st;
        int Idx = lower_bound(all(v),now+1)-v.begin();
        if( Idx ==v.size()-1) {
            ans++;
            v.push_back(inf);
        }
        v[Idx] = now;
    }
    return ans;
}

int main() {
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test) {
        N = II ;
        rep(i,N) Block[i].st = LL , Block[i].en = LL ;
        int ans = doll();
        printf("Case %d: %d\n",cs,ans);
    }
}
