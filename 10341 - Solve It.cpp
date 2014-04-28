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
DB p,q,r,s,t,u;
DB F(DB x)
{
    DB ans=p*exp(-x)+q*sin(x)+r*cos(x) + s*tan(x) + t*x*x + u;
    return ans;
}

DB Bisection()
{
        DB x,hi=1,lo=0;
        for(int i=1;i<=25;i++)
        {
            x=(hi+lo)/2;
            if(F(x)*F(lo)<=0) hi=x;
            else lo=x;
        }
    return x;
}
int main()
{
    //FRD;
    DB x;
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)==6)
    {
        if(F(1)*F(0)>0)printf("No solution\n");
        else           printf("%.4lf\n",Bisection());
    }
    return 0;
}
