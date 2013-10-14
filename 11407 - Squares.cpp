/*
    Royal_Flush , AUST
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
typedef long long ll;
typedef vector<int> vi ;
typedef vector<ll>vl;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
bool isVowel(char s){s=tolower(s); if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')return true;return false;}
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m
string i2b(ll a) {string s ;do { s += (a&1) + '0' ,  a >>= 1; }while(a);reverse(all(s));return s;}
ll toInt(string s){ll r = 0 ;istringstream sin(s); sin>>r;return r;}
string toString(ll number){stringstream ss; ss << number;return ss.str();}

int N ;
int Sqr[110];
int dp[10010];

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    rep(i,101) Sqr[i] = i * i ;
    For(i,10000) dp[i] = INF ;
    dp[0] = 0 ;
    for(int i = 1 ; i <= 100 ; i++ ){
        for(int j = Sqr[i] ; j <= 10000 ; j++ ){
            dp[j] = min( dp[j] , dp[ j - Sqr[i] ]+1 );
        }
    }
    int test = II ;
    For(cs,test){
        N = II ;
        printf("%d\n",dp[N]);
    }
}
