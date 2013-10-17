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

typedef pair<string,int>psi;

psi m[1100];

bool cmp(psi a , psi b){
    return a.second > b.second ;
}

int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
    int test = II ;
    For(cs,test){
        int N = II ;
        N = 1 << N ;
        rep(i,N) cin >> m[i].first >> m[i].second ;
        int Cnt = 1 ;
        sort(m,m+N,cmp);
        for(int i = 2 ; i < N ; Cnt++ ){
            sort(m+i,m+i+( 1 << Cnt) );
            i += ( 1 << Cnt );
        }
        rep(i,N) cout << m[i].first << endl;
    }
}
