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

const int MX = 107 ;
const int INF = 1e8 + 7;
Long a , b , c ;

bool f(Long x , Long y , Long z ){
    if( (x + y + z) != a ) return false ;
    if ( (x * y * z) != b ) return false ;
    if( (x*x + y * y  + z *z) != c) return false ;
    return true ;
}

#define sq(i) ((i)*(i))
int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    int test = II ;
    For(cs,test){
        Long x ,  y , z ;
        a = II , b =  II , c = II ;
        bool found = false ;
        forab(i,-100,100){
            forab(j,-100,100){
                forab(k,-100,100){
                    if( i == j || j == k || k == i ) continue ;
                    if( f(i,j,k) ) {
                            found = true ;
                            x = i , y = j , z = k ;
                            break ;
                    }
                }
                if( found ) break ;
            }
            if( found ) break ;
        }
        if(!found) puts("No solution.");
        else printf("%lld %lld %lld\n",x,y,z);
    }
}
