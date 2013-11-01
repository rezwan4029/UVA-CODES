/*
    Royal_Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-7
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi ;
typedef vector<ll>vl;

#define forab(i, a, b)  for (__typeof (b) i = (a), i##_b = (b); i <= i##_b; ++i)
#define rep(i, n)       forab (i, 0, (n) - 1)
#define For(i, n)       forab (i, 1, n)
#define rofba(i, a, b)  for (__typeof (b) i = (b), i##_a = (a); i >= i##_a; --i)
#define per(i, n)       rofba (i, 0, (n) - 1)
#define rof(i, n)       rofba (i, 1, n)
#define forstl(i, s)    for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


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
        return x > lox && x < hix && y > loy && y < hiy; // remove = (eq) if strictly in box need
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
    // 0    __ বৃত্তের বাইরে
    // 1 __ বৃত্তের  উপরে অবস্থিত
    // 2 __  বৃত্তের ভিতরে
    int relation(point b) // বৃত্ত  ও   একটি বিন্দুর সম্পর্ক
    {
        double dst = b.dis(p);
        if ( EQ( dst - r ) < 0 ) return 2;
        if ( EQ( dst - r ) == 0 ) return 1;
        return 0;
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
};

point rect[15][2];
bool RorC[15];
circle cir[15];

char s[10];
int main(){
    //freopen("in.txt","r",stdin);
    int n = 0 ;
    while(scanf("%s",&s)){
        if( s[0] == '*' )break ;
        if( s[0] == 'r' ){
            point a , b ;
            rect[n][0].input() ;
            rect[n][1].input() ;
        }
        else{
            cir[n].input();
            RorC[n] = true ;
        }
        n++;
    }
    point p ;
    int pNo = 0 ;
    while( true )
    {
        p.input() ;
        if( p.x == 9999.9 && p.y == 9999.9 )break;
        bool find = false ;
        ++pNo;
        rep(i,n)
        {
            if(RorC[i] == false ){
                if( p.in_box(rect[i][0],rect[i][1])  ){
                    printf("Point %d is contained in figure %d\n",pNo,i+1);
                    find = true ;
                }
            }
            else{
                if( cir[i].relation(p) == 2 ){
                    printf("Point %d is contained in figure %d\n",pNo,i+1);
                    find = true ;
                }
            }
        }
        if( find == false){
            printf("Point %d is not contained in any figure\n",pNo);
        }
    }
}
