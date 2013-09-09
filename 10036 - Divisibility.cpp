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
#define INF 1<<30
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
using namespace std;
typedef unsigned long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

int dp[10007][100];
int item[10007];
int n , K ;
int solve(int pos , int mod)
{
    if(pos == n ){
        if(mod == 0 )return 1 ;
        return 0 ;
    }
    int &ret = dp[ pos ][ mod ];
    if( ret != -1 )return ret;
    ret = solve(pos+1, ( (mod + item[pos])% K + K ) % K   ) ;
    ret |= solve(pos +1 , ( (mod - item[pos] )% K + K ) % K   ) ;
    return ret ;
}
int main()
{
  int test = II ;
  while(test--)
  {
     n = II , K = II ;
     rep(i,n) item[i] = II ;
     ms(dp,-1);
     int ret = solve(1, (item[0]+K)%K );
     printf("%s\n",ret ? "Divisible" : "Not divisible" );
  }
}
