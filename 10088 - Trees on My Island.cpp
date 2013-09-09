#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
#define i64 long long
i64  GCD(i64  a,i64  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}

struct point{ i64 x,y;
              point (i64 p1 , i64 p2){
                  x = p1;
                  y = p2;
              }
};

i64 poly_area( vector<point>P){ // calculate area of polygoan/convex

    i64 res = 0 , x1 ,y1,x2,y2;
    for( int i = 0 , sz = P.size() ; i < sz ; i++ ){
            x1 = P[i].x , x2 = P[(i+1)%sz].x;
            y1 = P[i].y , y2 = P[(i+1)%sz].y;
            res += ( x1 * y2 - x2 * y1 );
    }
    // res is the determinant of these points
    return fabs(res)*0.5 ;
}

i64 getBorderPoints(vector<point>P){

    i64 B = 0 ;
    int n = P.size();
    for( int i = 0, j = n - 1; i < n; j = i++ ) {

            i64 ret = GCD( abs( P[i].x - P[j].x ), abs( P[i].y - P[j].y ) );
            B += ret;
    }
    return B ;
}

int main()
{
    int i , n ;
    while(scanf("%d",&n) && n )
    {

        vector<point>P;
        for( i = 0 ; i < n ; i++ ){
                i64 x,y;
                scanf("%lld %lld",&x,&y);
                P.push_back( point(x,y) );
        }

        i64 A = poly_area(P);
        i64 B = getBorderPoints(P);
        i64 I = A + 1 - B/2 ;
        // picks theorem : A = I + B/2 - 1
        printf("%lld\n",I);
    }
}
