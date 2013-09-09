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

int n , sz ;
vector<int>ans;
bool taken[17];
int mat[17][17];
bool sol ;
void back(int u)
{
    if(ans.size() == sz )
    {
        sol = true;
        printf("(1");
        rep(i,sz) printf(",%d",ans[i]+1);
        puts(")");
        return;
    }
    for(int i = 0 ; i < n ; i++ )
    {
        if(taken[i] == false && mat[u][i]){
            taken[i] = true;
            ans.push_back(i);
            back(i);
            taken[i] = false;
            ans.pop_back();
        }
    }
}
int main()
{
    bool blnk = false;
    while(scanf("%d %d",&n,&sz)==2)
    {
        if(blnk)puts(""); blnk = 1 ;
        rep(i,n)rep(j,n)scanf("%d",&mat[i][j]);
        ans.clear();
        ms(taken,false);
        sol = false;
        taken[0] = true;
        back(0);
        if(sol == false) printf("no walk of length %d\n",sz);
        scanf("%d",&n);
    }
}
