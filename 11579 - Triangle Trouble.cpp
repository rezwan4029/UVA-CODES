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

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

bool valid( double a , double b , double c )
{
   if( a + b > c )return true ;
    if( b + c > a )return true ;
    if( a + c > b )return true ;
    return false ;
}
double area(double a , double b , double c )
{
    double s = (a+b+c) * .5 ;
    double area = sqrt( s * (s - a ) * ( s - b ) * ( s - c ) ) ;
    return area ;
}

double Tri[10010];

int main()
{
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        int  N = II ;
        rep(i,N) scanf("%lf",&Tri[i]);
        sort(Tri,Tri+N);
        reverse(Tri,Tri+N);
        double ans = 0.00 ;
        rep(i,N-2)
        {
            if( valid(Tri[i] , Tri[ (i+1)%N ] , Tri[ (i+2) %N ] ) )
            {
                ans = max( ans , area(Tri[i] , Tri[ (i+1)%N ] , Tri[ (i+2) %N ]) ) ;
            }
        }
        printf("%.2lf\n",ans);
    }
}
