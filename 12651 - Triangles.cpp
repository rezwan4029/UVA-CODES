/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

#define SZ 100007

int N ;
int a[SZ];
bool Used[SZ];

int main(){
    while(scanf("%d",&N) == 1 ){
        a[0] = 0 ;
        For(i,N) {
            a[i] = II ;
            a[i] += a[i-1];
        }
        if( a[N] % 3 != 0  ){
            puts("0");
            continue ;
        }
        a[N+1] = INF ;
        ms(Used,false);
        int L = a[N] / 3 , Cnt = 0 ;
        rep(i,N){
            if(Used[i])continue;
            int x = lower_bound(a , a+N+2 ,L+a[i] ) - a ;
            int y = lower_bound(a , a+N+2 ,L*2+a[i] ) - a ;
            if(a[x] == L +a[i] && a[y] == L*2+a[i] ){
                Cnt++;
                Used[x] = Used[y] = true ;
            }
        }
        printf("%d\n",Cnt);
    }
}
