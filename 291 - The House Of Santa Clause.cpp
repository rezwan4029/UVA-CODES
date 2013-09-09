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

int g[7][7];
bool taken[10][10];
int ans[10];

void back(int at ,  int deep)
{
    ans[deep] = at;

    if(deep == 9)
    {
        For(i,9)cout<<ans[i];
        cout<<endl;
        return;
    }
    For(i,5)
    {
        if(g[at][i] &&  taken[at][i] == false)
        {
            taken[at][i]  = taken[i][at] = true;
            back(i,deep+1);
            taken[at][i]  = taken[i][at] = false;
        }
    }
}
int main()
{
  memset(g,0,sizeof g);

  g[1][2] = g[2][1] = 1;
  g[1][5] = g[5][1] = 1 ;

  g[2][3] = g[3][2] = 1;
  g[2][5] = g[5][2] = 1 ;

  g[1][3] = g[3][1] = 1;
  g[3][5] = g[5][3] = 1 ;

  g[4][5] = g[5][4] = 1;
  g[3][4] = g[4][3] = 1 ;

  back(1,1);
}
