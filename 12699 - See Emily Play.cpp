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
const int MX = 1000002 ;
double dp[MX];
int vis[MX];
int d,s,a,mark;
double solve(int n ){
    if( n == 1 )return 0.0;
    double &ret = dp[n];
    if(vis[n] == mark) return ret;
    vis[n] = mark;
    ret = 0;
    if( n & 1 )
    {
        ret += solve(n+1)+a;
        ret += solve(n-1)+s;
        ret /= 2.;
    }
    else
    {
        ret += solve(n/2)+d;
    }
    return ret;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t = II ;
    For(cs,t){
        mark = cs;
        int n = II;
        d = II,s = II,a = II;
        printf("%.3lf\n",solve(n)+a+d+s);
    }
}
