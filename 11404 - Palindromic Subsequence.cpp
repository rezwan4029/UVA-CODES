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

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define LL long long
#define LLU unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define inpI ({int a; scanf(" %d", &a); a;})
#define inpD ({DB a; scanf(" %lf", &a); a;})
#define inpLL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction



#define MAXLEN 1000
char str[MAXLEN+1];

pair<int,string> dp[MAXLEN][MAXLEN];
bool dpVis[MAXLEN][MAXLEN];

pair<int,string> solve(int st, int end)
{
    pair<int,string> &ans = dp[st][end];


    if(dpVis[st][end]) return ans;

    dpVis[st][end]=true;

    if(st == end)
    {
        ans = mp(1, string(1, str[st]));
    }
    else if(st + 1 == end)
    {
        if(str[st] == str[end]) ans = mp(2, string(2, str[st]));
        else ans = mp(1, string(1, min(str[st], str[end])));
    }
    else
    {
        if(str[st] == str[end])
        {
            ans = solve(st + 1, end - 1);
            ans.first += 2;
            ans.second = str[st] + ans.second + str[end];
        }
        else
        {
             pair<int,string> rcut = solve(st, end - 1) ;
             pair<int,string> lcut = solve(st + 1, end) ;
            if(rcut.first == lcut.first)
            {
                ans = min(rcut, lcut);
            }
            else
            {
                ans = max(rcut, lcut);
            }
        }
    }
    return ans;
}

int main(){
    while(scanf("%s",&str) != EOF ){
        int len = strlen(str);
        memset(dpVis,false,sizeof dpVis);
        pair<int,string> ans = solve(0, len - 1);
        printf("%s\n", ans.second.c_str());
    }
}
