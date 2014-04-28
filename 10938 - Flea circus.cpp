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

#define SZ 5007

vector<int>Edge[SZ];
bool Vis[SZ];
int path[SZ];
int dist , st , en ;

void dfs(int u , int level){
    Vis[u] = true ;
    path[level] = u ;
    if(u == en){
        dist = level ;
        return ;
    }
    forstl(it,Edge[u]){
        int v = *it ;
        if(Vis[v])continue;
        dfs(v,level+1);
        if(dist != -1 )return ;
    }
}
int main(){
    int n ;
    while(cin >> n && n){
        rep(i,n-1){
            cin >> st >> en ;
            Edge[st].push_back(en);
            Edge[en].push_back(st);
        }
        int Q ;
        cin >> Q ;
        while(Q--){
            cin >> st >> en ;
            memset(Vis,false,sizeof Vis);
            dist = -1 ;
            dfs(st,0);
            if(dist % 2 == 0 )  printf("The fleas meet at %d.\n", path[ dist/2 ] );
            else{
                int a = path[ dist/2 ];
                int b = path[ dist/2+1 ];

                if( a <= b )
                    printf("The fleas jump forever between %d and %d.\n",a,b);
                else
                    printf("The fleas jump forever between %d and %d.\n",b,a);
            }
        }
        rep(i,n+1)Edge[i].clear();
    }
}
