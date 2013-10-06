/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 2*acos(0.0)
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

int main(){
    double l , w , h , theta ,theta1 ;
    while(cin >> l >> w >> h >> theta ){
        double theta1 = theta * pi / 180.00   ;
        //cout << theta << endl;
        double a = l ;
        double b = l * tan( theta1) ;
        double c = sqrt( a*a + b * b  );
       // cout << b << ' ' << c << endl;

        if( b <= h ){
            double s = (a+b+c)/2. ;
            double area = sqrt(s * (s-a) * (s-b) * (s-c) ) * w;
            double ans = (l * w * h ) - area ;
            printf("%.3lf mL\n",ans);
        }else{
            theta = ( 90 - theta ) * pi / 180.00   ;
            a = h ;
            b = h * tan(theta);
            c = sqrt( a*a + b * b );
            double s = (a+b+c)/2. ;
            double area = sqrt(s * (s-a) * (s-b) * (s-c) ) * w;
            printf("%.3lf mL\n",area);
        }
    }
}
