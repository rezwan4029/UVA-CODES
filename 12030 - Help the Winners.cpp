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

int check (LL mask,int i)
{
    return (mask &(1<<i));
}
LL on(LL mask,int k){
    return (mask|(1<<k));
}

LL  off(LL mask,int k){
    return (mask - (1<<k));
}

LL toggle(LL mask ,int k){
    return (mask^(1<<k));
}

int M[16][16],n;
LL memo[(1<<15)+5][2][2];

LL solve(int at,LL mask,int one,int two)
{

    if(at==n)
    {
        if(one || two)return 1;
        return 0;
    }

    LL &ret=memo[mask][one][two];

    if(ret!=-1) return ret;

    LL s=0;

    for(int i=0;i<n;i++)
    {
        if(check(mask,i))continue;

        if(M[at][i]==1)      s += solve(at+1,on(mask,i),one,two);
        else if(M[at][i]==2) s += solve(at+1,on(mask,i),one,1);
        else                 s += solve(at+1,on(mask,i),0,two);

    }

    return ret=s;
}
int main()
{
    //FRD;
    int i,j,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        memset(memo,-1,sizeof memo);
        for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&M[i][j]);
        CS;
        printf("%lld\n",solve(0,0,1,0));
    }
    return 0;
}
