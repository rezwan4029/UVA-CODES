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
#define EPS 1e-10
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

int main(){
    double x1 , x2 , y1 , y2 ;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2) != EOF ){
            double xMid = (x1+x2)/2. ;
            double yMid = (y1+y2)/2. ;
            double dX = xMid - x1 ;
            double dY = yMid - y1 ;

            double x3 = xMid - dY ;
            double y3 = yMid + dX ;
            double x4 = xMid + dY ;
            double y4 = yMid - dX ;

            printf("%.10lf %.10lf %.10lf %.10lf\n",x3,y3,x4,y4);
    }
}
