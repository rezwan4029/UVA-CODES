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
vector<char>ans;
bool taken[107];
char s[107];

void back()
{
    if(ans.size() == sz )
    {
        rep(i,sz) printf("%c",ans[i]);
        puts("");
        return;
    }
    for(int i = 0 ; i < n ; i++ )
    {
        if(ans.size() > 0 && ans[ ans.size()-1 ] > s[i] )  continue;

        if(taken[i] == false){
            taken[i] = true;
            ans.push_back(s[i]);
            back();
            taken[i] = false;
            ans.pop_back();
            while(s[i]==s[i+1] && i+1 < n )i++;
        }
    }
}
int main()
{
    while(scanf("%s %d",&s,&sz)==2)
    {
        n = strlen(s);
        sort(s,s+n);
        ans.clear();
        ms(taken,false);
        back();
    }
}
