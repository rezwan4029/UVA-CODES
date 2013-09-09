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
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

vector<int> pr;

void Seive()
{
    bool flag[1125] = {false};
    int sq = 34 , N = 1125 ;
    for(int i = 4 ; i <=  N ; i += 2 ) flag[i] = true;
    for(int i = 3 ; i <= sq ; i += 2){
        if(flag[i] == 0 ){
            for(int j = i*i ; j <= N ; j += i) flag[j] = true;
        }
    }
    flag[1] = true;
    For(i,N-2)if(flag[i] == false )pr.push_back(i) ;
}

int sum ,sz ;
int dp[1122][15];
/*
int dp[190][1122][15];
bool Vis[190][1122][15];

int solve(int pos , int currSum , int left )
{
    if( left == 0 ){
        if( currSum == sum )return 1 ;
        return 0;
    }

    if(pos >= sz )return 0;

    int &ret = dp[ pos ][currSum][left];
    if(Vis[ pos ][currSum][left])return ret;

    Vis[ pos ][currSum][left] = true;

    ret = solve(pos+1,currSum,left);
    if(currSum+pr[pos] <= sum ) ret += solve(pos+1,currSum+pr[pos],left-1);
    return ret;
}
*/
void solve()
{
    dp[0][0] = 1 ;
    for(int i = 0 ; i < sz ; i++ ){
        for( int j = 1120 ; j >= pr[i] ; j-- )
            for(int  k = 1 ; k < 15 ; k++ ){
                dp[j][k] += dp[ j - pr[i] ][k - 1];
        }
    }
}
int main()
{
    Seive();
    int n ;
    sz = pr.size();
    solve();
    while(scanf("%d %d",&sum,&n))
    {
        if( sum == 0 && n == 0 )break;
        //ms(Vis,false);
      //  int ret = solve(0,0,n);
        printf("%d\n",dp[sum][n]);
    }
}
