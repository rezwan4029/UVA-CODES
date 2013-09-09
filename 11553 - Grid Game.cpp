#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<climits>
#include<cctype>
using namespace std;
#define forstl(i,s) for( __typeof(s.begin())i = s.begin() ; i != s.end() ; i++ )
#define rep(i,s) for( __typeof(s)i = 0 ; i < s ; i++)
#define INF 99999
int n,G[9][9];
int dp[ 1<<8 + 5 ][1<<8 + 5];
bool v[ 1<<8 + 5 ][1<<8 + 5];
int solve(int maskR,int maskC)
{
    if( __builtin_popcount(maskR) == n &&  __builtin_popcount(maskC) == n)
    {
        return 0;
    }
    int &ret = dp[maskR][maskC];
    if(v[maskR][maskC] ) return ret;
    v[maskR][maskC] = true;

    ret = -INF;

    rep(i,n)
    {
        if(maskR & (1<<i))continue;

        int mn = INF;

        rep(j,n)
        {
            if(maskC & (1<<j) )continue;
            mn = min( mn , G[i][j]+solve(maskR|(1<<i),maskC|(1<<j)) );
        }
        ret = max(mn,ret);
    }

    return ret;
}
int main()
{
    int test , cs = 1 ;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        rep(i,n)rep(j,n)scanf("%d",&G[i][j]);
        memset(v,false,sizeof v);
        int ans = solve(0,0);
        cout << ans << endl;
    }
    return 0;
}
