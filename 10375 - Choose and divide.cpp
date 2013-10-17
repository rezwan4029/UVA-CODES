/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-9
#define INF 1<<30
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

double solve(int p , int q , int r , int s){
    q = min(q,p-q);
    s = min(s,r-s);
    p = p - q + 1;
    r = r - s + 1;
    double ret = 1.00 ;
    int i = 1 , j = 1 ;
    while(i <= q || j <= s){
        if(i <= q ){
            ret *= double(p);
            ret /= double(i);
            p++,i++;
        }
        if(j <= s){
            ret *=  double(j);
            ret /= double(r);
            j++,r++;
        }
    }
    return ret ;
}

int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
    int p , q , r , s ;
    while(scanf("%d %d %d %d",&p,&q,&r,&s) == 4){
        printf("%.5lf\n",solve(p,q,r,s));
    }
}
