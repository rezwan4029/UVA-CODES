#include<stdio.h>
#include<iostream>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

const int N = 10000005;
int lp[N+1];
vector<int>pr;


ll BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll)R;} //compute b^p%m

bool miller_rabin(ll a,ll n,ll t,ll u)
{
    ll x=BigMod(a,u,n);
    if(x==1) return true;
    while(t--)
    {
        if(x==n-1)return true;
        x=(x*x)%n;
    }
    return false;
}
bool isPrime(ll n)
{
    ll r=0,s=n-1;
    int count=4;
    if(n==1||(n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))return false;
    while(!(s&1)) {s>>=1;++r;}
    while(count--)
        if(!miller_rabin(rand()%(n-1)+1,n,r,s)) return false;
    return true;
}


void Seive()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
            {
                lp[i] = i;
                pr.push_back (i);
            }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j) lp[i * pr[j]] = pr[j];
    }
}
ll Divisors(ll n)
{
    if(n<0)n*=-1;
    if(n<4 || isPrime(n) )return -1;
    ll sq = sqrt(n);
    set<ll>ans;
    for( int i = 0 ; pr[i] <= sq ; i++ )
    {
        while(n % pr[i] == 0 )
        {
            n /= pr[i];
            ans.insert(pr[i]);
        }
    }
    set<ll>::iterator it;
    it = ans.end() ;
    if(n>1)ans.insert(n);
    if(ans.size()>1) return *(--it);
    return -1 ;
}
int main()
{
    Seive();
    int test , cs = 1;
    ll n ;
    while(scanf("%lld",&n)&&n)
    {
        printf("%lld\n",Divisors(n));
    }
    return 0;
}
