#include <sstream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int dp[104][104];
int row,col;
int dx[]={0,1};
int dy[]={1,0};
bool grid[104][104];
bool valid(int x,int y)
{
    if( x < row && y < col && grid[x][y] == false)return true;
    return false;
}
int solve(int x ,int y)
{

    if( x == row-1   && y == col-1 ) return 1;

    int &ret = dp[x][y];

    if(ret != -1 )return ret;
    ret = 0;
    for( int i = 0 ; i < 2 ; i++)
    {
        int nx = dx[i]+x;
        int ny = dy[i]+y;

        if(valid(nx,ny)) ret += solve(nx,ny);
    }
    return ret;
}
int main()
{
    int n,T;
    bool f = false;
    scanf("%d",&T);
    while(T--)
    {
      scanf("%d%d",&row,&col);
      memset(dp,-1,sizeof dp);
      memset(grid,false,sizeof grid);
      string s;
      getline(cin,s);
      for( int i = 0 ; i < row ; i++ )
      {
          getline(cin,s);
          stringstream sin(s);
          int p, q; sin >> p;
          while(sin >> q) {
                grid[p-1][q-1] = true;
            }
      }
      if(f)puts("");
      int ans = solve(0,0);
      cout<<ans<<endl;
      f = true;
    }
}
