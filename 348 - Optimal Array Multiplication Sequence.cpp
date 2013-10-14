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
int X[12],Y[12];
int dp[12][12];
int dir[12][12];

int solve(int from , int to ){
    if(from == to ) return 0 ;
    int &ret = dp[from][to];
    if(ret != -1 )return ret ;
    ret = INF ;
    forab(it,from,to-1){
        int calc = solve(from,it)+solve(it+1,to)+ X[from]*Y[it]*Y[to] ;
        if( ret > calc ){
                ret = calc ;
                dir[from][to] = it ;
        }
    }
    return ret ;
}

void print(int from , int to){
    if( from == to )printf("A%d",from);
    else
    {
            printf("(");
            print(from , dir[from][to] );
            printf(" x ");
            print(dir[from][to]+1 , to );
            printf(")");
    }
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1 ;
    while( scanf("%d",&N) && N ){
          For(i,N) X[i] = II , Y[i] = II ;
          ms(dp,-1);
          solve(1,N);
          printf("Case %d: ",cs++);
          print(1,N);
          puts("");
    }
}
