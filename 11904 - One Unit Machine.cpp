/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include <queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

#define mod 1000000007

ll  BigMod(ll  B,ll  P){ ll  R=1 , M = mod ; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m
ll  modInv(ll x) { return BigMod(x,mod-2) ; }

ll F[1000007];
ll Finv[1000007];

void generate()
{
    Finv[0] = F[0] = 1;

    For(i,1000000ll)
    {
        F[i] = (F[i-1]*i)%mod;
        Finv[i] = ( Finv[i-1] * modInv(i) ) % mod ;
    }
}
int main()
{
    generate();

    int test , cs = 1 ;
    scanf("%d",&test);
    while(test--)
    {
        int n , s = 0;
        scanf("%d",&n);
        ll ans = 1 ;
        For(i,n)
        {
            int x ;
            scanf("%d",&x);
            ans =  ( ans * F[ s+x-1 ] ) % mod ;
            ans =  ( ans * Finv[x-1] ) % mod ;
            ans =  ( ans * Finv[s] ) % mod ;
            s += x ;
            //  fact(s+x-1) / (    fact(x-1) * fact(s)  )
           // nCr ; n = s+x-1 ,, r = s
        }
        printf("Case %d: %lld\n",cs++,ans);
    }
}
