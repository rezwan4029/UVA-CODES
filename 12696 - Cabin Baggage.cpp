/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
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

const double INF = 1000000;

int main(){
    //freopen("in.txt","r",stdin);
    int n ;
    while( scanf("%d",&n) != EOF ){
        int Cnt = 0 ;
        rep(i,n) {
            double len , wid , dep , wgth ;
            scanf("%lf %lf %lf %lf",&len , &wid , &dep ,&wgth);
            if( ( (len <= 56.00 && wid <= 45.00 && dep <= 25.00 ) || ( len + wid + dep <= 125.00 ) ) && wgth <= 7.00  )
            {
                  Cnt++ ; puts("1");
            }
            else puts("0");
        }
        printf("%d\n",Cnt);
    }
}
