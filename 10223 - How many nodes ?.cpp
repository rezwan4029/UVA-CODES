/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll ;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll Catalan[30];

void __getCatalan(){
    Catalan[0] = Catalan[1] = 1 , Catalan[2] = 2 ;
    forab(n,3,26LL) Catalan[n] =  Catalan[ n - 1 ] * (2*( n*2 - 1 )) / (n+1)    ;

    //For(i,26) cout << i << " -> "<< Catalan[i] << "  \n" ; cout << endl ;
}
int main(){
    __getCatalan();
    ll n ;
    while(scanf("%lld",&n)==1){
        int Cnt = 0 ;
        For(i,26){
            if(Catalan[i] > n ) break ;
            Cnt++;
        }
        printf("%d\n",Cnt);
    }
}
