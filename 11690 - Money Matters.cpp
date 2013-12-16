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

const int MX = 10000 + 7 ;
const int INF = 1e8 + 7;

int prev[MX];
int Cost[MX];

int Parent(int i){
    if(i==prev[i])return i;
    return ( prev[i] = Parent( prev[i] ) );
}

int isUnion(int a,int b){
    return Parent(a) == Parent(b);
}

void makeUnion(int a,int b ){
    prev[ Parent(a) ] = Parent(b);
}

set<Long> St[MX];

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        int N = II , M = II ;
        rep(i,N) Cost[i] = II ;
        rep(i,N) prev[i] = i ;
        rep(i,M){
            int x = II , y = II ;
            if( !isUnion(x,y) ) makeUnion(x,y);
        }
        rep(i,N) St[ Parent(i) ].insert( i );
        set<Long> ret ;
        rep(i,N){
            if( St[i].size() == 0 ) continue ;
            Long sum = 0 ;
            forstl(j,St[i]) sum += Cost[ *j ];
            ret.insert( sum );
        }
        if(ret.size() == 1 ) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
        rep(i,N) St[i].clear();
    }
}
