/*
    rezwan4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; read(a) ; a;})
#define LL ({Long a; read(a) ; a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

#define CS printf("Case #%d:",cs)

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print
template<class T> inline void MAX(T &a , T b){ if (a < b ) a = b;}
template<class T> inline void MIN(T &a , T b){ if (a > b ) a = b;}

//Fast Reader
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


int EQ(double d)
{
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

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
    point rotate(point p,double angle) { // angle must be in radian
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
    // মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং বর্তমান বিন্দুর সাথে co-linear
    point trunc(double r)
    {
        double l = hypot(x,y);
        if ( !EQ(l) )return *this;
        r /= l ;
        return point(x*r,y*r);
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


struct line
{
    point a , b ;
    line(point _a , point _b )
    {
        a = _a , b = _b ;
    }
    line() {}
    bool operator==(line v)
    {
        return (a==v.a) && (b==v.b);
    }
    // ** ভুমির সাথে  থিটা কোণে  নতুন রেখা উৎপন্ন  করে এবং থিটা রেডিয়ান  এ হতে হবে .
    line(point p,double theta)
    {
        a = p;
        if ( EQ( theta - pi/2.00 ) == 0 ) b = a + point(0,1);
        else b= a + point( 1 , tan( theta ) );
    }
    //ax+by+c=0 ,a,b,c দেয়া আছে তার জন্য রেখার দুইটা বিন্দু তৈরি করে
    line(double _a,double _b,double _c)
    {
        if ( EQ( _a ) == 0)
        {
            a = point(0,-_c/_b);
            b = point(1,-_c/_b);
        }
        else if (EQ(_b)==0)
        {
            a = point(-_c/_a,0);
            b = point(-_c/_a,1);
        }
        else
        {
            a = point(0,-_c/_b);
            b = point(1,(-_c-_a)/_b);
        }
    }
    //দুইটা বিন্দুর  মধ্যবর্তী দূরূত্ব
    double length()
    {
        return a.dis(b);
    }
    //ভুমির সাথে কত ডিগ্রী কোনে রেখাটি  অবস্থিত
    // return করতেছে রেডিয়ানে  //   angle 0 <= angle < pi
    double angle()
    {
        double k = atan2(b.y-a.y,b.x-a.x);
        if (EQ(k) < 0)k += pi;
        if (EQ(k-pi) == 0)k -= pi;
        return k;
    }
    // একটি বিন্দু থেকে লাইন এর লম্বদূরত্ব
    double dispointtoline(point p)
    {
        return fabs((p-a).cross((b-a)))/length();
    }

    // dont know the usage :p
    point lineprog(point p)
    {
        double d = (b - a).x * (b - a).x + (b - a).y * (b - a).y ;
        return a + ((b-a)*((b-a).dot((p-a))/d) );
    }
    //প্রতিবিম্ব বিন্দু /  Shadow point
    point symmetrypoint(point p)
    {
        point q = lineprog(p);
        return point(2 * q.x - p.x , 2 * q.y - p.y );
    }
    void input()
    {
        a.input() ;
        b.input();
    }
};


int turn( point O , point A , point B) { //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}


// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if segments intersect first
// **use LinesParallel and LinesColliner to detect wether they intersect
point ComputeLineIntersection(point a, point b, point c, point d)
{
    b = b - a ;
    d = c - d ;
    c = c - a ;
    assert( b.dot(b) > EPS && d.dot(d) > EPS);
    return a + b* c.cross(d) / b.cross(d) ;
}

// compute center of circle given three points
point ComputeCircleCenter(point a, point b, point c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+(a-b).rotright(), c, c+(a-c).rotright()); // global
}


// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<point> CircleLineIntersection(point a, point b, point c, double r) {
    vector<point> ret;
    b = b-a;
    a = a-c;
    double A = b.dot(b) , B = a.dot(b) , C = a.dot(a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}



struct circle
{
    point p ;  //  বৃত্তের কেন্দ্র
    double r ; // বৃত্তের  ব্যাসার্ধ
    circle() {}
    circle(point _p, double _r)
    {
        p = _p , r = _r ;
    }
    bool operator ==(circle v)
    {
        return (( p == v.p ) && EQ( r - v.r ) == 0 );
    }
    bool operator <(circle v)const
    {
        return ((p < v.p )||(p == v.p) && EQ( r - v.r ) < 0 );
    }
    double area() //  বৃত্তের  ক্ষেত্রফল
    {
        return pi*r*r;
    }
    double circumference() //বৃত্তের  পরিধি
    {
        return 2*pi*r;
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
};



//যদি  ABC ত্রিভুজ গঠন করতে পারে তাহলে ABC এর  বহিবৃত্ত উৎপন্ন করে এমন Circle তৈরী করে ।
circle Circum_circle(point a,point b,point c)
{
    point center = ComputeCircleCenter(a,b,c); // global
    double  radius = center.dis(a); // point.h
    return circle(center,radius);
}


point A,B,C,P;

int main ()
{
   // FI ;

    int cs = 1;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&P.x, &P.y) !=EOF)
    {
        if(P == A || P == B || P == C)
        {
            printf("Case %d: %.3lf\n", cs++, 0.0);
            continue;
        }
        circle c = Circum_circle(A,B,C);

        line OP = line( c.p , P );

        vector<point> Inter = CircleLineIntersection( OP.a , OP.b , c.p , c.r ) ;

        point P1 = Inter[0] ;
        point P2 = Inter[1] ;

        double Ans = min(  P.dis(A) , P.dis(B) ) ;
        Ans = min( Ans , P.dis(C) ) ;

        if( turn(A,B,C) == turn(A,P1,C) ) Ans = min( Ans , P.dis(P1) ) ;
        if( turn(A,B,C) == turn(A,P2,C) ) Ans = min( Ans , P.dis(P2) ) ;

        printf("Case %d: %.3lf\n",cs++,Ans);
    }
}
