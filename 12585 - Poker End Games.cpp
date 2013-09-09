#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define forstl(i,n) for( __typeof(n.begin()) i= n.begin() ; i != n.end() ; i++) 
#define FOR(i,n) for( __typeof(n) i = 1 ; i <= n ; i++ ) 


bool v[355][355];
double solve(int a ,int b)
{
       if( v[a][b] ) return 2.;
       if( a == b ) return 1.;
       v[a][b] = true;
       int c = min(a,b);
       double ret ;
       if(a >b) ret = 1 + solve( a - c , b+ c)*.5  ;
       else     ret = 1 + solve( a + c , b- c)*.5 ;
       return ret ; 
}
int main()
{
  int t , a , b ,cs = 1;
  cin >> t ;
  while(t--)
  {
    memset(v,false,sizeof v);
    cin >> a >> b ;
    double p = double(a) / double(a+b);
    double ret = solve(a,b);
    printf("Case %d: %.6lf %.6lf\n",cs++,ret,p);
  }   
}
