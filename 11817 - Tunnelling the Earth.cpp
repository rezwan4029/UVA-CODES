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

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const double R = 6371009.00 ; // radius of earth / sphere

// great Circle in Sphere / points must be in radian / distance between 2 pnts on earth
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {
       double dlon = lon2 - lon1;
       double dlat = lat2 - lat1;
       double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
       double c = 2 * atan2(sqrt(a), sqrt(1-a));
       double d = R * c;
       double e = sqrt(2.*R*R *(1-cos(c)));
       return round(d-e+EPS);
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int t = II ;
    while(t--){
        double ax , ay , bx , by;
        scanf("%lf %lf",&ax,&ay);
        scanf("%lf %lf",&bx,&by);
        ax*=pi/180.00;
        ay*=pi/180.00;
        bx*=pi/180.00;
        by*=pi/180.00;
        ll ans = ll( .5 + spherical_distance(ax,ay,bx,by) );
        printf("%lld\n",ans);
    }
}

