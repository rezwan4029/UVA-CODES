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

#define mod   100000007

vector<int>g[107],ans;
int n,indeg[107];

void top()
{
    queue<int>Q;
    For(i,n)if(!indeg[i]) Q.push(i);
    while(!Q.empty()){
       int u = Q.front(); Q.pop();
       ans.pb(u);
       forstl(it,g[u]){
          indeg[ *it ]--;
          if(indeg[*it] == 0 ) Q.push(*it);
       }
    }
}
int main()
{
    int m;
    while(scanf("%d %d",&n,&m)==2){
        if( n == 0 && m == 0 ) break;
        rep(i,m){
            int x , y ;
            scanf("%d %d",&x,&y);
            g[x].pb(y);
            indeg[y]++;
        }
        top();
        rep(i,n){
            if(i)printf(" ");
            cout << ans[i];
        }puts("");
        rep(i,n+1)g[i].clear(),indeg[i] = 0 ;ans.clear();
    }
    return 0 ;
}
