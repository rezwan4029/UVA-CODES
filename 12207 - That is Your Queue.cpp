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

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

char Str[10];
ll p , c ;
int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1 ;
    while( scanf("%lld %lld",&p,&c) ){
        if( p == 0 && c == 0 ) break ;
        deque<ll>Q;
        for(int i = 1 ; i <= p && i <= 1000 ; i++ )Q.push_back(i);
        ll x ;
        printf("Case %d:\n",cs++);
        while(c--) {
            scanf("%s",&Str);
            if( Str[0] == 'N' ) {
                x = Q.front() ;
                Q.pop_front();
                Q.push_back(x);
                printf("%lld\n",x);
            }
            else {
                scanf("%lld",&x);
                forstl(i,Q)if(*i == x ){ Q.erase(i) ; break ; }
                Q.push_front(x);
            }
        }
    }
}
