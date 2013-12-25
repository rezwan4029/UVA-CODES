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

const int MX = 1e5 + 7 ;
const int INF = 1e8 + 7;

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
    void translate(double tx, double ty) {
        x += tx;
        y += ty;
    }
    point translate(point t) {
        x += t.x;
        y += t.y;
    }
    point operator+(point k){
        return point(x + k.x , y + k.y );
    }
    point operator-(point k){
        return point(x - k.x , y - k.y );
    }
    point operator*(double k) {
        return point(k * x , k * y );
    }
    point operator/(double k) {
        return point(x / k , y/k );
    }
    point rotleft(){
        return point(-y,x);
    }
    point rotright(){
        return point(y,-x);
    }
    point rotate(point p,double angle) {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
    #define sqr(x) ((x)*(x))
    double sqrdis(const point &b)const {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const {
        return sqrt(sqrdis(b));
    }
    bool operator ==(const point &p)const {
        return ((x==p.x) && (y==p.y));
    }
    bool collinear(const point &p1, const point &p2)const  {
        return (p1.y - y) * (p2.x - x) == (p2.y - y) * (p1.x - x);
    }
    double cross(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    double dot(const point &i)const
    {
        return x*i.x+y*i.y;
    }

    bool in_box(const point &a, const point &b) const { // rectangle : a = leftDown , b = rightTop
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return x >= lox && x <= hix && y >= loy && y <= hiy; // remove = (eq) if strictly in box need
    }

    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend ostream& operator<<(ostream& out, const point& p) {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};


bool PointInPoly( point Pt,vector<point> Pl){
    long Rcross = 0; /* number of right edge/ray crossings */
    long Lcross = 0; /* number of left edge/ray crossings */
    int N = Pl.size() ;
    /* Shift so that Pt is the origin. Note this destroys the polygon.*/
    rep(i,N){
        Pl[i].x = Pl[i].x - Pt.x ;
        Pl[i].y = Pl[i].y - Pt.y ;
    }
    /* For each edge e=(i-1,i), see if crosses ray. */
    rep(i,N){
        /* First see if Pt=(0,0) is a vertex. */
        if( Pl[i].x==0 and Pl[i].y==0 ) return 1;
        long j = (i+N-1)%N;

        bool Rstrad = (Pl[i].y>0) != (Pl[j].y>0);
        bool Lstrad = (Pl[i].y<0) != (Pl[j].y<0);

        /* if e "straddles" the x-axis... */
        if( Rstrad or Lstrad ){
            /* e straddles ray, so compute intersection with ray. */
            double x = ( Pl[i].x*(double)Pl[j].y - Pl[j].x*(double)Pl[i].y) / (double)(Pl[j].y-Pl[i].y);
            /* crosses ray if strictly positive intersection. */
            if( Rstrad and x>0 ) Rcross++;
            if( Lstrad and x<0 ) Lcross++;
        }
    }
    /* Pt on the edge if left and right cross are not the same parity. */
    if( (Rcross%2) != (Lcross%2) ) return 1;
    /* Pt inside iff an odd number of crossings. */
    if( (Rcross%2) == 1 ) return 1;
    else return 0;
}

struct Seg {
    point s, e;
};

inline bool onsegment(const point &p1, const point &p2, const point &p3) {
    point pmn, pmx;
    pmn.x = min(p1.x, p2.x), pmn.y = min(p1.y, p2.y);
    pmx.x = max(p1.x, p2.x), pmx.y = max(p1.y, p2.y);
    return pmn.x <= p3.x && p3.x <= pmx.x && pmn.y <= p3.y && p3.y <= pmx.y;
}


int SegmentIntersection(Seg a, Seg b, point &p) {
    double a1 = a.s.y - a.e.y, b1 = -a.s.x + a.e.x;
    double a2 = b.s.y - b.e.y, b2 = -b.s.x + b.e.x;
    double c1 = a1 * a.s.x + b1*a.s.y;
    double c2 = a2 * b.s.x + b2*b.s.y;
    double D =  a1 * b2  - a2 * b1;
    double Dx = c1 * b2  - c2 * b1;
    double Dy = a1 * c2  - a2 * c1;
    if( fabs(D) < EPS ) return 0; // NONE or LINE
    p.x = Dx/D , p.y = Dy/D;
    return onsegment(a.s , a.e , p) && onsegment(b.s , b.e , p) ;
}


point Pt[MX];

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int N , M ;
    while( scanf("%d",&N) && N ){

        vector<point>poly1(N) ;
        rep(i,N) poly1[i].input();
        scanf("%d",&M);
        vector<point>poly2(M) ;
        rep(i,M) poly2[i].input();

        Seg s1 , s2 ;

        int nn = 0 ;

        for( int i = 0 , j = N - 1 ; i < N ; j = i++ ){
            s1.s = poly1[i];
            s1.e = poly1[j];
            for( int k = 0 , l = M - 1 ; k < M ; l = k++ ){
                s2.s = poly2[k];
                s2.e = poly2[l];
                point pp ;
                if( SegmentIntersection(s1,s2,pp) ) Pt[ nn++] =  pp ;
            }
        }

        rep(i,N) if( PointInPoly(poly1[i],poly2) )  Pt[ nn++ ] =  poly1[i] ;

        rep(i,M) if( PointInPoly(poly2[i],poly1) )  Pt[ nn++ ] =  poly2[i] ;

        if( nn == 0 ) {
            puts("0") ;
            continue ;
        }

        sort( Pt , Pt + nn  );

        int j = 0 ;
        rep(i,nn){
             if( fabs( Pt[i].x - Pt[j].x ) > EPS || fabs( Pt[i].y - Pt[j].y ) > EPS )
                Pt[++j] = Pt[i];
        }

        nn = j + 1 ;
        printf("%d\n",nn);
        rep(i,nn) printf("%.2lf %.2lf\n",Pt[i].x , Pt[i].y );
    }
}
