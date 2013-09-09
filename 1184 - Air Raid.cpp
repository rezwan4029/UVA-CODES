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
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64 long long
#define i64U unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795


int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;

#define SZ 1005

vector<int>edges[SZ];
int matchLeft[SZ],matchRight[SZ];
bool V[SZ];
int n,m;

bool Match(int u)
{
    int i,v;
    REP(i,edges[u].size())
    {
        v= edges[u][i];
        if(V[v])continue;
        V[v]=true;
        if(matchRight[v] == -1 || Match(matchRight[v]) )
        {
            matchLeft[u]  = v;
            matchRight[v] = u;
            return true;
        }
    }
    return false;
}
int BPM()
{
    int ret=0,i,flag;

    while(true)
    {
        flag=0;

        ms0(V);

        REP(i,n)
        {
            if(matchLeft[i]!=-1)continue;

            if(Match(i))
            {
                flag=1;
                ret++;
            }
        }
        if(flag==0)break;
    }

    return ret;

}
int main()
{
    int t=II,cs=1,i;
    while(t--)
    {
       n=II;
       m=II;
       REP(i,n+1)edges[i].clear();
       REP(i,m)
       {
           int u=II,v=II;
           u--,v--;
           edges[u].pb(v);
       }

       msn(matchLeft,-1);
       msn(matchRight,-1);
       int ret=BPM();
      // CS;
       printf("%d\n",n-ret);
    }
    return 0;
}
