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

#define FRD freopen("in.txt", "r", stdin)


int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);



using namespace std;
using namespace std;

int check (int mask,int i)
{
    return (mask &(1<<i));
}
int on(int mask,int k){
    return (mask|(1<<k));
}

LL  off(LL mask,int k){
    return (mask - (1<<k));
}

int toggle(int mask ,int k){
    return (mask^(1<<k));
}

int M[25][25],n;
int memo[21][(1<<20)+5];
pair<int,int>P[21];

int dist(int x1,int y1,int x2,int y2)
{
    return (abs(x2-x1)+abs(y2-y1));
}

int solve(int at,int mask)
{

    if(mask==(1<<n)-1)return M[at][0];

    int &ret = memo[at][mask];
    if(ret!=-1) return ret;
    ret=inf;
    for(int i=0;i<n;i++)
    {
        if(check(mask,i) || i==at)continue;
        //cout<<"at :"<<at<<" ";
        ret=min(ret,M[at][i]+solve(i,on(mask,i)));
    }
    return ret;
}
int main()
{
    //FRD;
    int i,j,t,cs=1,r,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        cin>>P[0].first>>P[0].second;
        memset(memo,-1,sizeof memo);
        cin>>n;
        ++n;
        for(i=1;i<n;i++)scanf("%d %d",&P[i].first,&P[i].second);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                M[i][j]=dist(P[i].first,P[i].second,P[j].first,P[j].second);

        //CS;
        printf("The shortest path has length %d\n",solve(0,1));
    }
    return 0;
}
