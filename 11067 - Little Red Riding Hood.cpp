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
    if( x <= row && y <= col && grid[x][y] == false)return true;
    return false;
}
int solve(int x ,int y)
{

    if( x == row   && y == col ) return 1;

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
    int n;
    while(scanf("%d%d",&row,&col))
    {
      if(row+col == 0)break;
      memset(dp,-1,sizeof dp);
      memset(grid,false,sizeof grid);
      scanf("%d",&n);
      while(n--)
      {
          int p ,q;
          scanf("%d%d",&p,&q);
          grid[p][q]=true;
      }

      int ans = solve(0,0);
      if(ans == 0 )puts("There is no path.");
      else if(ans == 1 )puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
      else printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",ans);
    }
}
