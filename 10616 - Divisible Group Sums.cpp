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

int n , m , d;
int data[207];
ll dp[207][11][21];
bool v[207][11][21];
ll solve(int pos , int taken , int sum )
{
    if(taken == m)
    {
            if( sum == 0 ) return 1 ;
            return 0 ;
    }
    if(pos == n ) return 0;

    ll &ret = dp[ pos ][ taken ][ sum ];
    if( v[ pos ][ taken ][ sum ] ) return ret;
    v[ pos ][ taken ][ sum ] = true;
    ret = solve(pos+1,taken+1, ((sum + data[pos])%d+d)%d ) + solve(pos+1,taken,sum) ;
    return ret;
}
int main()
{
    int test , cs = 1 ,q;

    while(scanf("%d %d",&n,&q))
    {
       if( n == 0 && q == 0 )break;

       printf("SET %d:\n",cs++);

       rep(i,n)scanf("%d",&data[i]);

       For(Q,q)
       {
           ms(v,false);
           scanf("%d %d",&d,&m);
           ll ret = solve(0,0,0);
           printf("QUERY %d: %lld\n",Q,ret);
       }
    }
}
