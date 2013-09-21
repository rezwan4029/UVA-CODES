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

int main(){
    int N , I , J ;
    while( scanf("%d %d %d",&N,&I,&J) == 3 ){
        if( I > J ) swap(I,J);
        int round ;
        for(round = 1 ; round <= N ; round ++ ){
            //cout << "ROUND #" << round << "  : "<< I << "  " << J << endl ;
            if( I % 2 == 1 && J % 2 == 0  && (J - I) == 1 ) break ;
            if( I % 2 == 0 ) I >>= 1 ;
            else I = (I + 1 ) >> 1 ;

            if( J % 2 == 0 ) J >>= 1 ;
            else J = (J + 1 )>> 1 ;

            if(I > J )swap(I,J);
        }
        printf("%d\n",round);
    }
}
