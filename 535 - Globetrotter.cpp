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


struct point {
    double x,y;
    point(){
        x = y = 0;
    }
    point(double x, double y) : x(x), y(y) {}
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    point (const point &p) {
        x = p.x, y = p.y;
    }
    #define sqr(x) ((x)*(x))
    double sqrdis(const point &b)const {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const {
        return sqrt(sqrdis(b));
    }
};

const double R = 6378.00 ; // radius of earth / sphere

// great Circle in Sphere / points must be in radian / distance between 2 pnts on earth
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {
       double dlon = lon2 - lon1;
       double dlat = lat2 - lat1;
       double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
       double c = 2 * atan2(sqrt(a), sqrt(1-a));
       double d = R * c;
       return d+EPS;
}

int main()
{
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    map<string,point>Map;
    string s1 , s2 ;
    while(cin >> s1 )
    {
        if( s1 == "#" )break ;
        point p ;
        p.input() ;
        p.x = ( p.x * pi / 180.00 ) ;
        p.y = ( p.y * pi / 180.00 ) ;
        Map[ s1 ] = p ;
    }
    while( cin >> s1 >> s2 )
    {
        if(  s1 == "#"  &&  s2 == "#"  ) break ;
        cout << s1 << " - " << s2 << endl;
        if( Map.find(s1) == Map.end() || Map.find(s2) == Map.end() )
        {
            puts("Unknown");
            continue;
        }
        if( s1 == s2 )
        {
            puts("0 km");
            continue ;
        }
        point p = Map[ s1 ];
        point q = Map[ s2 ];
        double ans = spherical_distance(p.x,p.y,q.x,q.y);
        printf("%lld km\n",ll(ans+.5));
    }
}
