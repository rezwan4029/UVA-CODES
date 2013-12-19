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

class point{
    public :
    int x , y ;
    point(int _x , int _y){
        x = _x , y = _y ;
    }
    point(){}
    void Input(){
        scanf("%d %d",&x,&y);
    }
};

class Segment{
    public :
    point a , b ;
    Segment(point _a , point _b){
        a = _a, b = _b ;
    }
    Segment(){}
    void Input(){
        a.Input();
        b.Input();
    }
};


int turn( point O , point A , point B){
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

inline bool onSegment(const point &p1, const point &p2, const point &p3) {
    point pmn, pmx;
    pmn.x = min(p1.x, p2.x), pmn.y = min(p1.y, p2.y);
    pmx.x = max(p1.x, p2.x), pmx.y = max(p1.y, p2.y);
    return pmn.x <= p3.x && p3.x <= pmx.x && pmn.y <= p3.y && p3.y <= pmx.y;
}

inline bool Intersect(const point &p1, const point &p2, const point &p3, const point &p4, bool &on) {
    int d1, d2, d3, d4;
    d1 = turn(p3, p4, p1);
    d2 = turn(p3, p4, p2);
    d3 = turn(p1, p2, p3);
    d4 = turn(p1, p2, p4);
    on = false;
    if(((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) return true;
    if( !d3 && onSegment(p1, p2, p3)) { on = true; return true; }
    if( !d4 && onSegment(p1, p2, p4)) return true;
    if( !d1 && onSegment(p3, p4, p1)) return true;
    if( !d2 && onSegment(p3, p4, p2)) return true;
    return false;
}

int main(){
     #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        vector<Segment>Seg;
        int N = II ;
        rep(i,N){
            Segment s ;
            s.Input();
            if( s.a.x > s.b.x ) swap( s.a , s.b );
            Seg.pb(s);
        }
        int M = II ;
        For(q,M){
            point p1 ;
            p1.Input();
            while(true){
                point p2 = point(p1.x,0);
                bool ON ;
                int Mx = -1 ,Idx ;
                rep(i,N){
                    if( Intersect(Seg[i].a,Seg[i].b,p1,p2,ON) ){
                        if( Seg[i].a.y > Mx && !ON) Mx = Seg[i].a.y , Idx = i ;
                    }
                }
                if( Mx == -1 ) break;
                if( Seg[ Idx ].a.y > Seg[ Idx ].b.y ) p1 = Seg[ Idx ].b ;
                else p1 = Seg[ Idx ].a ;
            }
            printf("%d\n",p1.x);
        }
        if( cs != test ) puts("");
    }
}
