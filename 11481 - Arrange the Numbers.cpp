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


ll  nCr[1005][1005];
ll fact[1005];

void combination()
{
    int i,j;
    nCr[0][0] = 1;
    for(i=1;i<=1000;i++) {
        nCr[i][0] = 1;
        for(j=1;j<=i;j++) {
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%mod;
        }
    }
}
void F()
{
    int i;
    fact[0]=fact[1]=1;
    for(i=2;i<=1000;i++) fact[i] = (i*fact[i-1])%mod;
}

int main()
{
    F();combination();
    int T , cs = 1 , n , m , k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        ll ans = 0;

        for(int i = 0; i <= m - k; i++)
        {
            if(i&1) ans = ans - nCr[m-k][i]*fact[n-k-i];
            else    ans = ans + nCr[m-k][i]*fact[n-k-i];

            ans%=mod;
        }
        ans = (ans * nCr[m][k])%mod;
        ans = (ans+mod)%mod;
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}
