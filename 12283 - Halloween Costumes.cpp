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

int n,m,c[107];
int dp[107][107];

int solve(int start ,int end)
{
    if(start > end) return 0;
    int &ret = dp[start][end];
    if(ret != -1)return ret;
    ret = min (solve(start+1,end) +1 , solve(start,end-1) +1 ) ;
    for(int pos = start +1; pos <= n ; pos++){
        if( c[pos] == c[start]) ret = min ( ret ,  solve(start+1,pos) + solve(pos+1,end)  ) ;
    }
    return ret;
}

int main()
{
   int test , cs = 1 ;
   scanf("%d",&test);
   while(test--)
   {
       scanf("%d %d",&n,&m);
       For(i,n)scanf("%d",&c[i]);
       ms(dp,-1);
       printf("Case %d: %d\n",cs++,solve(1,n));
   }
}
