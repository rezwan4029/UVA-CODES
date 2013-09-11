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


int main()
{
    //FRD;
     int n,i;
     char s[11];
     bool V[11];
     ms0(V);
     while(scanf("%d",&n) && n)
     {
         scanf("%s %s",&s,&s);
         if(s[0]=='h')
         {
             for(i=n;i<=10;i++)V[i]=true;
         }
         else if(s[0]=='l')
         {
             for(i=n;i>=1;i--)V[i]=true;
         }
         else
         {
             if(!V[n])printf("Stan may be honest\n");
             else     printf("Stan is dishonest\n");
             ms0(V);
         }
     }
     return 0;
}
