/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 10109999990
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64 long long
#define i64U unsigned long long
#define DB double
#define LD long double
#define EPS 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({i64 a; scanf(" %lld", &a); a;})
#define CS printf("Case #%d: ",cs++)
#define PI 3.1415926535897932384626433832795

#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)

int cs = 1;

//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;

#define dist(a,b)  (sqrt(SQR(a.x-b.x) + SQR(a.y-b.y)))

struct Point {
        DB x, y;
        Point(DB ix=0, DB iy=0) { x=ix, y = iy; }
        bool operator <(const Point &p) const {
                return x < p.x || (x == p.x && y < p.y);
        }
};

// 2D cross product.
// Return a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
DB cross(const Point &O, const Point &A, const Point &B)
{
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
// Note: no two points should be same
// (take a set to make all point unique before sending to convex hull)
vector<Point> convexHull(vector<Point> P)
{
        int n = P.size(), k = 0;
        vector<Point> H(2*n);

        // Sort points lexicographically by angles
        sort(P.begin(), P.end());

        // Build lower hull
        for (int i = 0; i < n; i++) {
                while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

        // Build upper hull
        for (int i = n-2, t = k+1; i >= 0; i--) {
                while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

        H.resize(k);
        return H;
}

DB find_angle(Point A, Point B, Point C)
{
    // angle find in degree for radiant use x*180/PI
    DB x = dist(B, C);
    DB y = dist(C, A);
    DB z = dist(A, B);
    return acos((z*z + x*x - y*y)/(2*z*x));
}

DB calc_areaofConvex(vector<Point>P)
{
    // Area of a Polygoan // no repeating co - ordinates
    DB a = 0.0 ;
    int i,sz  = P.size();
   // REP(i,sz)  a += P[ (i+1)%sz ].y * P[i].x - P[ (i+1)%sz ].x * P[i].y;
    REP(i,sz)  a += cross( P[i] , P[ (i+1)%sz ] ,P[0]);
    a = fabs(a) * 0.5;

    return a ;
}

int main()
{
    vector<Point>xy,hullPoints;
    int i,n ,T = 0;
    while( scanf("%d",&n) &&n )
    {
        if(T)puts("") ; T = 1 ;
        xy.clear();hullPoints.clear();

        REP(i,n){
                 DB x = DD ,y = DD ;
                 xy.pb( Point(x,y) );
        }

        hullPoints = convexHull(xy);
     /*   for( i = 0 ; i< hullPoints.size() ;i++ )
                cout<<"( " << hullPoints[i].x << ", "<< hullPoints[i].y<<" )\n";*/

       // hullPoints.pop_back(); // last one comes again so you can use set

        int sz =hullPoints.size() ;

        printf("Region #%d:\n",cs++);

         for( i = sz -1 ; i>=0 ;i-- )
         {
            if( i!=sz-1) printf("-");
            printf("(%.1lf,%.1lf)",hullPoints[i].x,hullPoints[i].y);
         }

        DB peri = 0;
        REP(i,sz-1) peri += dist( hullPoints[i] , hullPoints[i+1] ) ;
        printf("\nPerimeter length = %.2lf\n",peri);

    }
  //  system("pause");
    return 0;
}
