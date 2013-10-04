/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )


#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))

struct point {
#define Type double
    Type x,y;
    point() {
        x = y = 0;
    }
    point(Type x, Type y) : x(x), y(y) {}
    point (const point &p) {
        x = p.x, y = p.y;
    }
    void translate(Type tx, Type ty) {
        x += tx;
        y += ty;
    }
    point translate(point t) {
        x += t.x;
        y += t.y;
    }
    point operator+(const point  &k)const {
        return point(x + k.x , y + k.y );
    }
    point operator-(const point  &k)const {
        return point(x - k.x , y - k.y );
    }
    point operator*(const double k) {
        return point(k * x , k * y );
    }

    point rotate(point p,double angle) {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
#define sqr(x) ((x)*(x))
    Type sqrdis(const point &b)const {
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

    inline double cross(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    inline double dot(const point &i)const
    {
        return x*i.x+y*i.y;
    }

    bool operator <(const point &p) const {
        return x > p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend istream& operator>>(istream& inp, point& p){
        inp >> p.x >> p.y;
        return inp;
    }
    friend ostream& operator<<(ostream& out, const point& p) {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

struct line { // Creates a line with equation ax + by + c = 0
    double a, b, c;
    line(){}
    line( point p1,point p2 ) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = a*p1.x + b*p1.y ;
    }
    bool is_parallel(line &l) {
        return (abs(a * l.b - b * l.a) < EPS );
    }
    bool intersection( line L, point &p ) { // returns intersection point of Two Lines
        double det = a * L.b - b * L.a;
        if( equal( det, 0 ) ) {
            if( (c - a)/b == (L.c - L.a)/L.b ) ; //sameLine = true ; // if two lines lies in same
            return false; // parallel
        }
        p.x = ( L.b * c - b * L.c ) / det;
        p.y = ( L.c * a - c * L.a ) / det;
        return true;
    }
};

point P[105];

int main(){
    //freopen("in.txt", "r", stdin);
    int test = II ;
    For(cs,test){
        int n = II ;
        rep(i,n) cin >> P[i] ;
        sort(P,P+n);
        //rep(i,n) cout << P[i] << endl;
        point Curr = P[1];
        double dist = Curr.dis( P[0] );
        forab(i,2,n-1){
            if( P[i].y < Curr.y )continue ;
            line A = line( P[i] , P[i-1] );
            line B = line( Curr , point(0,Curr.y) );
            //cout << B.a << "  " << B.b <<  "  " << B.c << endl;
            point hit ;
            A.intersection(B,hit);
            dist += ( P[i].dis(hit) ) ;
            Curr = P[i];
        }
        printf("%.2lf\n",dist);
    }
}
