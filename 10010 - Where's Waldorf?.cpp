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

char grid[57][57],str[57];
int row , col , len ;


bool solve(int x , int y)
{
    int j = 0 ;
    for(int i = y ; i < col  && j < len ; i++,j++ ) if(grid[x][i] != str[j] ) break; // right
    if(j == len ) return true ;

    j = 0 ;
    for(int i = y ; i >= 0  && j < len ; i-- , j++ ) if(grid[x][i] != str[j] ) break; // left
    if(j == len ) return true ;

    j = 0 ;
    for(int i = x ; i < row  && j < len ; i++,j++ ) if(grid[i][y] != str[j] ) break; // down
    if(j == len ) return true ;

    j = 0 ;
    for(int i = x ; i >= 0  && j < len ; i-- , j++ ) if(grid[i][y] != str[j] ) break; // up
    if(j == len ) return true ;

    j = 0 ;
    for(int i = x ; i < row  && j < len  && (y+j) < col ; i++,j++ ) if(grid[i][y+j] != str[j] ) break; // right dia down
    if(j == len ) return true ;


    j = 0 ;
    for(int i = x ; i < row   && j < len  && (y-j) >= 0 ; i++,j++ ) if(grid[i][y-j] != str[j] ) break; // left dia down
    if(j == len ) return true ;


    j = 0 ;
    for( ; (x-j) >= 0  && (y-j) >= 0 && j < len ; j++ ) if(grid[x-j][y-j] != str[j] ) break; // left dia up
    if(j == len ) return true ;

    j = 0 ;
    for( ; (x+j) < row  && (y-j) >= 0 && j < len ; j++ ) if(grid[x+j][y-j] != str[j] ) break; // right dia up
    if(j == len ) return true ;

    return false;
}
pair<int,int>solve()
{
    rep(i,row)rep(j,col){
        if( grid[i][j] == str[0] ){
            if( solve(i,j) ) return make_pair(i+1,j+1);
        }
    }
}
int main()
{
   int test ;
   scanf("%d",&test);
   while(test--)
   {
      scanf("%d %d",&row,&col);
      rep(i,row) scanf("%s",grid[i]);
      rep(i,row)rep(j,col) grid[i][j] = tolower(grid[i][j]);
      int q ;
      scanf("%d",&q);
      while(q--)
      {
          scanf("%s",&str);
          len = strlen(str);
          rep(i,len) str[i] = tolower(str[i]);
          pair<int,int>ret = solve();
          printf("%d %d\n",ret.first,ret.second);
      }
      if(test)puts("");
   }
}
