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

int main()
{
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    double R , N ;
    while( scanf("%lf %lf",&R,&N) != EOF )
    {
        if( N == 1 )
        {
            printf("%.10lf %.10lf %.10lf\n",R,0.0,0.0);
            continue ;
        }
        if( N == 2 )
        {
            printf("%.10lf %.10lf %.10lf\n",R/2.00,0.0,pi*R*R/2.00);
            continue ;
        }
        double angle = pi / N ;
        double alpha = sin( angle );
        double r = ( R * alpha ) / ( 1.00 + alpha );
        double a = 2.00 * r ;
        double H = sqrt( (R-r) * (R-r) - r*r ) ;
        double I = N * r * (  H - (pi/2 - angle)*r );
        double E = pi * R*R - I - ( N * pi * r * r );
        printf("%.10lf %.10lf %.10lf\n",r,I,E);
    }
}
