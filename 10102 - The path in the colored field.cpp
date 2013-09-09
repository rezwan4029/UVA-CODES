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

char grid[1007][1007];
int n ;
int solve(int x , int y){
    int dist = INF ;
    rep(i,n)rep(j,n)if(grid[i][j]=='3'){
        dist = min( dist , abs(x-i) + abs(y-j) );
    }
    return dist;
}
int main()
{
    while(scanf("%d",&n) == 1)
    {
        rep(i,n) scanf("%s",grid[i]) ;
        int ans = 0;
        rep(i,n)rep(j,n)if(grid[i][j]=='1') ans = max( ans,solve(i,j) );
        printf("%d\n",ans);
    }
}
