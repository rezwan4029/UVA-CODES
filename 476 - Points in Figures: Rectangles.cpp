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


struct point {
    double x,y;
    point(){
        x = y = 0;
    }
    point(double x, double y) : x(x), y(y) {}
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    bool in_box(const point &a, const point &b) const { // rectangle : a = leftDown , b = rightTop
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return x > lox && x < hix && y > loy && y < hiy; // remove = (eq) if strictly in box need
    }

};


point rect[15][2];

char s[10];
int main(){
    freopen("in.txt","r",stdin);
    int n = 0 ;
    while(scanf("%s",&s)){
        if( s[0] == '*' )break ;
        point a , b ;
        rect[n][0].input() ;
        rect[n][1].input() ;
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
        rep(i,n){
            if( p.in_box(rect[i][0],rect[i][1])  ){
                printf("Point %d is contained in figure %d\n",pNo,i+1);
                find = true ;
            }
        }
        if( find == false){
            printf("Point %d is not contained in any figure\n",pNo);
        }
    }
}
