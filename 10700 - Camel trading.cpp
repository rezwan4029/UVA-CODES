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

int N , opCnt ;
char Str[210];
char Op[15];
pair<ll,ll> dp[15][15];
bool Vis[15][15];
vl A;

pair<ll,ll> solve(int st , int en){
    if( st == en )return make_pair(A[st],A[st]);
    pair<ll,ll> &ret = dp[st][en];
    if( Vis[st][en] ) return ret ;
    Vis[st][en] = true;
    ret = make_pair(100000000000000000000000LL,-1000000000000000000000000LL);
    forab(it,st,en-1){
        if(Op[it] == '+'){
            ret.first = min( ret.first , solve(st,it).first + solve(it+1,en).first);
            ret.second = max( ret.second , solve(st,it).second + solve(it+1,en).second);
        }
        else{
            ret.first = min( ret.first , solve(st,it).first * solve(it+1,en).first);
            ret.second = max( ret.second , solve(st,it).second * solve(it+1,en).second);
        }
    }
    return ret ;
}
void Init(){
    A.clear();
    opCnt = 0;
    int len = strlen(Str);
    string s ;
    rep(i,len){
        if( Str[i] == '+' || Str[i] == '*' ) {
            Op[ opCnt++ ] = Str[i];
            if(s.size()) {
                int Num = toInt(s);
                s.clear();
                A.pb(Num);
            }
        }
        else{
            s += Str[i];
        }
    }
    if(s.size())A.pb( toInt(s) );
    N = A.size();
}
int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        scanf("%s",&Str);
        Init();
        ms(Vis,false);
        pair<ll,ll>ans = solve(0,N-1);
        printf("The maximum and minimum are %lld and %lld.\n",ans.second,ans.first);
    }
}
