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

#define maximum_cap  50005
#define maximum_item 105
int solve[maximum_item][maximum_cap],Taken[maximum_item];
int items,maxWeight,W[maximum_item],Profit[maximum_item];
int KnapsacK()
{
    int i,w;
    FOR(i,items)solve[i][0]=0;
    for(int i=0;i<=maxWeight;i++)solve[0][i]=0;
    for(i=1;i<=items;i++)
        for(w=0;w<=maxWeight;w++)
        {
            if(W[i]>w)
            {
                solve[i][w]=solve[i-1][w];
            }
            else
            {
                if(solve[i-1][w] > solve[i-1][ w-W[i] ]+W[i])
                {
                    solve[i][w]=solve[i-1][w];
                }
                else
                {
                  solve[i][w]=solve[i-1][ w-W[i] ]+W[i];
                }
            }
        }
    return solve[items][maxWeight];
}

int main()
{
    int T=inpI,cs=1,i;
    while(T--)
    {
        ms0(Taken);
        items=inpI;
        maxWeight=0;
        FOR(i,items)    //Profit[i]=inpI
           {

            W[i]=inpI;
            maxWeight+=W[i];
           }
        int tot=maxWeight;
        maxWeight>>=1;
        int ret=KnapsacK();
       // CS;
      //  cout<<ret<<endl;
        cout<<tot-ret*2<<endl;
    }
    return 0;
}
