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

vector< pair<int,int> >g[100];
int n , m;
double dp[(1<<15)+7][16];
bool vis1[(1<<15)+7][16];

double dp2[(1<<15)+7][16];
bool vis2[(1<<15)+7][16];

bool dfs(int mask,int u){
    if(__builtin_popcount(mask)==n){
        return true;
    }
    if(vis2[mask][u]) return dp2[mask][u];
    vis2[mask][u] = true;
    bool r = false;
    forstl(it,g[u]){
        int tmp = it->first;
        if(mask & (1<<tmp) ) continue;
        r |= dfs( mask|(1<<tmp),tmp);
    }
    return dp2[mask][u] = r ;
}


double solve(int mask,int lastVisit)
{
    if(__builtin_popcount(mask)==n)return 0.0;
    double &ret = dp[ mask][ lastVisit ];
    if(vis1[mask][lastVisit]) return ret;
    vis1[mask][lastVisit] = true;

    ret = 5.00 ;
    int cnt = 0 ;
    forstl(it,g[lastVisit]){
        int now = it->first;
        if(mask & (1 << now)) continue;
        if(dfs(mask|1<<now,now) == false) continue; // if possible to go all EJs
        cnt++;
        double cost = double( it->second );
        ret += (cost+solve(mask|1<<now,now)) ;
    }
    if(cnt) ret *= 1. / double(cnt) ;
    else ret -= 5.00 ;
    return ret ;
}
int main()
{
    int test , cs = 1 ;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        rep(i,m){
            int x , y  ,z ;
            cin >> x >> y >> z;
            g[x].pb(make_pair(y,z));
            g[y].pb(make_pair(x,z));
        }
        ms(vis1,0); ms(vis2,0);
        double ret = solve(1,0);
        printf("Case %d: %.10lf\n",cs++,ret);
        rep(i,n)g[i].clear();
    }
}
