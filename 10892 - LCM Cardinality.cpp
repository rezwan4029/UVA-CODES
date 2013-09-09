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
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

ll  GCD(ll  a,ll  b){ while(b){b ^= a ^= b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }

vector<int>divs;

void solve( ll n)
{
    divs.clear();
    ll sq  = sqrt(n);
    For(i,sq)
    {
        if(n % i == 0 )
        {
            divs.push_back(i);
            ll x = n / i ;
            if(x != i )divs.push_back(x);
        }
    }
    //forstl(it,divs)cout << *it << ","; puts("");
}
int main()
{
    ll n  ;
    while( scanf("%lld",&n) && n ){
        solve(n);
        int sz = divs.size();
        int ret = 0 ;
        for(int i = 0 ; i < sz ; i++ )
            for(int j = i + 1 ; j < sz ; j++ )
                if( LCM( divs[i] ,divs[j]  ) == n) ret++;
        printf("%lld %d\n",n,ret+1);
    }
}


