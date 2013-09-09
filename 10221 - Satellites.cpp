#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define pi 3.1415926535897932384626433832795
using namespace std;
#define rep(i,n) for( __typeof(n) i = 0 ; i < n ; i++ )
#define forstl(i,n) for( __typeof(n.begin()) i = n.begin() ; i!= n.end() ; i++ )

int main()
{
    double earth_rad = 6440 ;
    double s , ang ;
    string type;
    while(cin>> s >> ang >> type){
                double R = earth_rad + s ;
                if( type == "min" ) {
                    ang /= 60. ;
                }
                if( ang > 180 ) ang = 360 - ang ;
                ang *= pi / 180. ;
                double len = sqrt( R*R + R*R - 2. * R * R * cos(ang) );
                double arc =  R * ang ;
                printf("%.6lf %.6lf\n",arc,len);
    }
}


// A*A = B*B + C*C - 2BC Cos (a) 
