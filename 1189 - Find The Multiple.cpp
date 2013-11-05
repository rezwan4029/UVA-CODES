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
#define EPS 1e-12
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

int n ;
int dp[102][102];
int solve(int pos , int rem )
{
    if( pos == 100 )return 0 ;
    if( rem == 0 )return  1 ;
    int &ret = dp[pos][rem];
    if( ret != -1 )return ret ;
    ret =  solve(pos+1, (rem * 10 + 1 ) % n ) ;
    ret |= solve(pos+1, (rem * 10 + 0 ) % n ) ;
    return ret ;
}
void print(int pos , int rem ){
    if(pos == 100 )return ;
    if( rem == 0 ) return ;
    if( solve(pos+1, (rem * 10 + 1 ) % n ) )
    {
        printf("1");
        print(pos+1, (rem * 10 + 1 ) % n ) ;
    }
    else
    {
        printf("0");
        print(pos+1, (rem * 10 + 0 ) % n ) ;
    }
}
int main()
{
    #ifdef LOCAL
     freopen ("in.txt", "r", stdin);
    #endif
    while ( scanf("%d",&n) && n)
    {
        ms(dp,-1);
        solve(0,n);
        print(0,n);
        puts("");
    }
}
