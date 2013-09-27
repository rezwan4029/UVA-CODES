/*
    Royal Flush , AUST
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

ll superCatalan[28] , Catalan[28] ;
void __getSuperCatalan(){
    superCatalan[0] = superCatalan[1] = superCatalan[2] = 1 ;
    forab(n,3,26LL) superCatalan [ n ] = ( 3 * ( n*2 - 3 ) * superCatalan[n-1] - (n - 3) * superCatalan[ n - 2 ] ) / n;

    //For(i,26) cout << superCatalan[i] << "  " ; cout << endl ;
}
void __getCatalan(){
    Catalan[0] = Catalan[1] = 1 , Catalan[2] = 2 ;
    forab(n,3,26LL) Catalan[n] =  Catalan[ n - 1 ] * (2*( n*2 - 1 )) / (n+1)    ;

    //For(i,26) cout << i << " -> "<< Catalan[i] << "  \n" ; cout << endl ;
}
int main(){
    __getSuperCatalan();
    __getCatalan();
    int N ;
    while(scanf("%d",&N)==1){
        printf("%lld\n",superCatalan[N] - Catalan[N-1]);
    }
}
