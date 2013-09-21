/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with(0);cin.tie(0);
#define pb push_back
#define INF 1<<30
#define all(x) (x.begin(),x.end() )
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef unsigned long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

bool Vis[10007];
int main(){
    int n , r ;
    while( scanf("%d %d",&n,&r) == 2 ){
        ms(Vis,false);
        rep(i,r){
            int x = II ;
            Vis[x] = true ;
        }
        int Cnt = 0 ;
        For(i,n){
            if(!Vis[i]){
                Cnt++;
                printf("%d ",i);
            }
        }
        if(Cnt == 0 )printf("*");
        printf("\n");
    }
}
