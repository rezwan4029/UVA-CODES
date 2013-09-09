#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#define max(a,b)a>b?a:b
using namespace std;
int dp[1005][1005];
char s1[1005],s2[1005];
int solve(int i,int j)
{
    if(i<0 || j<0)return 0;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    if(s1[i]==s2[j])ret=solve(i-1,j-1)+1;
    else            ret=max(solve(i-1,j),solve(i,j-1));
    return ret;
}
 
int main()
{   
    while(gets(s1))
    {
        gets(s2);
        memset(dp,-1,sizeof dp);
        cout<<solve(strlen(s1)-1,strlen(s2)-1)<<endl;
     
    }
    return 0;
}
