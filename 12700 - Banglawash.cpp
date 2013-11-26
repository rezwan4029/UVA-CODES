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
char s[1000000];
int M[200];
int main(){
    //freopen("in.txt","r",stdin);
    int t = II ;
    For(cs,t){
        int n = II ;
        scanf("%s",&s);
        ms(M,0);
        for(int i = 0 ; s[i] ; i++) M[ s[i] ]++;
        printf("Case %d: ",cs);
        if( (M[ 'W' ] == 0  && M['B'] > 0)  && M[ 'T' ] == 0  )  puts("BANGLAWASH");
        else if( M[ 'B' ] == 0  && M['W'] > 0 &&  M[ 'T' ] == 0 ) puts("WHITEWASH");
        else if( M['A'] == n ) puts("ABANDONED");
        else if( M['B'] > M[ 'W'] ) printf("BANGLADESH %d - %d\n",M['B'],M['W']);
        else if( M['B'] < M[ 'W'] ) printf("WWW %d - %d\n",M['W'],M['B']);
        else printf("DRAW %d %d\n",M['W'],M['T']);
    }
}
