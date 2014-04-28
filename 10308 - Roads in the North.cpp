/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <set>
#include <sstream>
#include <utility>
using namespace std;

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define show_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}

int cs = 1 ;

#define INF 10109999990
#define msn(a,n) memset(a,n,sizeof(a))
#define i64 long long
#define i64U unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define PB pop_back
#define mp make_pair
#define all(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795

#define pii pair< int ,int >
#define pll pair< i64 ,i64 >
#define vi  vector < int >
#define si  set < int >
#define ins insert
#define F first
#define S second


#define mx 10015
vector<pii>edges[mx];
bool V[mx],present[mx];
int cost[mx] ;
void dfs( int u)
{
    V[ u ] =true ;
    int i , sz = edges[u].size();
    REP(i,sz){
        int v = edges[u][i].F;
        if( V[ v  ] ) continue ;
        cost[v] = cost[u] + edges[u][i].S ;
        dfs( v ) ;
    }
}
int main()
{

    int i;
    char str[55];
    bool oK = true ;
    while(oK)
    {
        int node = 0 ;
        while(true){
            if( gets(str) == NULL ){
               oK = false;
               break;
            }
            else if(str[0]){
                int u ,v ,w ;
                sscanf(str,"%d %d %d",&u,&v,&w);
                edges[u].pb( pii(v,w) ) ;
                edges[v].pb( pii(u,w) ) ;
                node = max ( node , max( u, v ) ) ;
                present[u]=present[v] = true ;
            }
            else break ;
        }
        dfs(1);
        int TreeDiameter = 0 ,next = 1;
        FOR(i,node){
            if( present[i] == false )continue ;
            if( TreeDiameter < cost[i]){
                TreeDiameter = cost[i] ;
                next = i ;
            }
        }
       //cout << next <<endl;
        msn(V,0 ); msn( cost , 0 ) ;
        dfs( next );
        FOR(i,node){
            if( present[i] == false )continue ;
            if( TreeDiameter < cost[i]){
                TreeDiameter = cost[i] ;
            }
            V[ i ] = cost[i] = present[i] = 0 ;
            edges[i].clear();
        }
        edges[0].clear() ;
        printf("%d\n",TreeDiameter);
    }
}
