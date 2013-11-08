/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

bool valid(double a, double b, double c, double d)
{
     if( a - d > EPS ) return false ;

     double theta = acos( ( a*a + b*b - c*c )/(2*a*b) ) ;

     double alpha = acos( a/d ); // since d = 2*r ; diameter

     double eta = theta - alpha ;

     double xx = d*cos(eta) ;

     return (xx-b > -EPS );
}

double D[102];
int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int m = II ;
    rep(i,m){
        scanf("%lf",&D[i]);
        D[i] = D[i];
    }
    int n = II ;
    rep(i,n){
        double x , y , z , t ;
        scanf("%lf %lf %lf",&x,&y,&z);
        bool flag = false ;
        rep(j,m){
            if( valid(x,y,z,D[j]) || valid(y,z,x,D[j]) || valid(z,x,y,D[j]) ){
                if(flag)printf(" %d",j+1);
                if(!flag)printf("Peg %c will fit into hole(s): %d",i+'A',j+1);
                flag = true ;
            }
        }
        if( !flag ){
            printf("Peg %c will not fit into any holes\n",i+'A');
        }else puts("");
    }
}
