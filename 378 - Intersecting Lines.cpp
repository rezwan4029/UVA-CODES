/*
    Rezwan_4029
    AUST , CSE-25
*/
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)




struct point{
    double x , y ;
    point(double _x , double _y ){
        x = _x , y = _y ;
    }
    point(){}
};
struct line{
    double a , b , c ;
    line(point p1 , point p2 ){
        a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = p1.x * p2.y - p2.x * p1.y;
    }
    line(){}
};

bool intersection( line L1, line L2, point &p , bool &sameLine ) { // returns intersection point of Two Lines
    #define eps 1e-9
    #define eq(a, b) fabs( a - b ) < eps
	double det = L1.a * L2.b - L1.b * L2.a;
	if( eq ( det, 0 ) ) {
        if( (L1.c - L1.a)/L1.b == (L2.c - L2.a)/L2.b ) sameLine = true;
        return false;
	}
	p.x = ( L1.b * L2.c - L2.b * L1.c ) / det;
	p.y = ( L1.c * L2.a - L2.c * L1.a ) / det;
	return true;
}

int main(){
        puts("INTERSECTING LINES OUTPUT");
        int test ; scanf("%d",&test);
        while(test--){
            point p , p1 , p2 , p3 , p4 ;
            cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y ;
            line l1 = line(p1,p2) , l2 = line(p3,p4);
            bool sameLine = false ;
            bool Int = intersection(l1,l2,p,sameLine);
            if(Int)printf("POINT %.2lf %.2lf\n",p.x ,p.y);
            else   printf("%s\n",sameLine ? "LINE" : "NONE" ) ;
        }
        puts("END OF OUTPUT");
}
