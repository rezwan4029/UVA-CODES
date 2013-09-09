/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<cmath>
#include<sstream>
#include<map>
#include<queue>
#include<climits>
#include<algorithm>
#include<stdlib.h>
#define pb push_back
#define eps 1e-8
#define CS printf("Case #%d: ",cs++)
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
#define PI 3.1415926535897932384626433832795
using namespace std;
typedef  long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

#define pA(a,n) { rep(i,n) printf("%d ",a[i]) ; cout << endl; }

string toString(int number){ stringstream ss;ss << number; return ss.str(); }
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char s){s=tolower(s); if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')return true;return false;}
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
void SWAP(ll  &a,ll  &b){ a = a ^ b; b = a ^ b ;a = a ^ b; }
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;}
ll  ModInv(ll  A , ll M ){ return BigMod(A,M-2,M) ; }
int D[1000007];
int ret[1000007];

int num_Divisors(int n){
  int res = 1;
  for(int i = 2; i*i <= n; i++){
    int cnt = 0;
    while(!(n%i)) n /= i , cnt++ ;
    if(cnt) res *= (++cnt) ;
  }
  if(n > 1) res <<= 1 ;
  return res;
}

int main(){
    for(int i = 1 ; i <= 1000000 ; i++ ) D[i] = num_Divisors(i);
    int mx = 1 , pos = 1 ;
    For(i,1000000) {
        if( D[i] >= mx ){
                ret[i] = i ;
                pos = i ;
                mx = D[i] ;
        } else ret[i] = pos ;
    }
    int test  = II ;
    while(test--){
        int n = II ;
        printf("%d\n",ret[n]);
    }
}
