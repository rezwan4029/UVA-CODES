/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 307 ;
const int INF = 1e8 + 7;


#define MX 200007
const int inf = 1e8 + 7 ;
struct Node{ int x,y ; };

Node Block[MX];
int N ;

// condition : x2 > x1 and y2 > y1
bool cmp(Node a,Node b){
    if( a.y == b.y ) return a.x < b.x;
    return a.y > b.y;
}

int Doll(){
    vi v ;
    sort(Block,Block+N,cmp);
    v.push_back(inf);
    int ans = 0;
    rep(i,N) {
        int now = Block[i].x;
        int Idx = lower_bound(all(v),now+1)-v.begin();
        if( Idx == v.size()-1) {
            ans++;
            v.push_back(inf);
        }
        v[Idx] = now;
    }
    return ans;
}


int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    int test = II ;
    For(cs,test){
        N = II ;
        rep(i,N) Block[i].x = II , Block[i].y = II ;
        printf("%d\n",Doll());
    }
}
