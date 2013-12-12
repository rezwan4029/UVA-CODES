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

const int MX = 107 ;
const int INF = 1e8 + 7;
char g[MX][MX];
int Sum[MX][MX] , n , m  ;


void Update(int r, int c , int x) {
	int ret = x ;
	ret += Sum[r-1][c];
	ret += Sum[r][c-1];
	ret -= Sum[r-1][c-1];
	Sum[r][c] = ret ;
}

int getSum(int r1 , int c1 , int r2 , int c2){
    int ret = 0 ;
    ret += Sum[r2][c2];
    ret -= Sum[r1-1][c2];
    ret -= Sum[r2][c1-1];
    ret += Sum[r1-1][c1-1];
    return  ret ;
}

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    while( scanf("%d",&n) && n  ){
        scanf("%d",&m);
        ms(Sum,0);
        rep(i,n) scanf("%s",g[i]);
        For(i,n) For(j,m) if( g[i-1][j-1] == '1' ) Update(i,j,1) ; else Update(i,j,0);
        int Ans = 0 ;
        For(i,n) For(j,m) forab(k,i,n) forab(l,j,m){
            if( getSum(i,j,k,l) == ( (k-i+1) * (l-j+1) ) ) Ans++;
        }
        printf("%d\n",Ans);
    }
}
