#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define forstl(it,s) for( __typeof(s.begin())it = s.begin() ; it != s.end() ; it++)
vector<int>e[1999000 + 10],rev[1999000 + 10];
bool V[2005];
vector<int>Top;

void dfs1(int u){
    V[u] = true;
    forstl(it,e[u]){
        if(V[*it]) continue;
        dfs1(*it);
    }
    Top.push_back(u);
}


void dfs2(int u){
    V[u] = true;
    forstl(it,rev[u]){
        if(V[*it]) continue;
        dfs2(*it);
    }
}

int main()
{
    int n , m ;
    while(scanf("%d %d",&n,&m)){
        if( n == 0 && m == 0 )break ;
        for(int i = 0 ; i < m ; i++){
            int u , v , p ;
            scanf("%d %d %d",&u,&v,&p);
            e[u].push_back(v);
            rev[v].push_back(u);
            if(p == 2 ) {
                e[v].push_back(u);
                rev[u].push_back(v);
            }
        }
        memset(V,false,sizeof V);
        for(int i = 1 ; i <= n ; i++ ) if(!V[i]) dfs1(i);

        reverse(Top.begin(),Top.end());
        memset(V,false,sizeof V);
        int ans = 0 ;
        forstl(it,Top){
            if(V[*it])continue ;
            dfs2(*it);
            ans++;
        }
        for(int i = 1 ; i <= n ; i++ ) e[i].clear() , rev[i].clear() ; Top.clear();

        printf("%d\n",ans == 1 ? 1 :0 ) ;
    }
}
