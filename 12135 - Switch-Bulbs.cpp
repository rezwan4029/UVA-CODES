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

const int INF = 1e7 ;
int nBulb , mSwitches ;
int Lights[47];
int d[(1<<15)+7];

int solve(){
    rep(i,(1<<nBulb)+2) d[i] = INF ;
    d[0] = 0 ;
    queue<int>Q;
    Q.push(0);
    while(!Q.empty()){
        int curr = Q.front() ; Q.pop();
        for(int i = 0 ; i < mSwitches ; i++ ){
            int mask = curr ;
            mask ^= Lights[i];
            if( d[mask] > d[curr]+1 ){
                d[ mask ] = d[curr] + 1 ;
                Q.push(mask);
            }
        }
    }
}
char Str[47];
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
    int test = II ;
    For(cs,test){
        nBulb = II ;
        mSwitches = II ;
        rep(i,mSwitches){
            int No_of_Blubs = II ;
            Lights[i] = 0 ;
            rep(j,No_of_Blubs) {
                int x = II ;
                Lights[i] |= (1<<x);
            }
        }
        solve();
        int Q = II ;
        printf("Case %d:\n",cs);
        while(Q--) {
            scanf("%s",&Str);
            int mask = 0 ;
            int len = strlen(Str);
            rep(i,len) if( Str[i] == '1' ) mask |= 1<<(nBulb-i-1) ;
            printf("%d\n",d[mask] == INF ? -1 : d[mask]);
        }
        puts("");
    }
}
