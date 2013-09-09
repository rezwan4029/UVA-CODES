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
int cs = 1;

//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;

int row,col;
char mat[105][105];

int solveThisColumn(int c)
{
       int i,cnt1,cnt2,ans=0,j1,j2;
       for(i= 0 ;i < row ;i++)
               {
                   cnt1  = cnt2 = 1;

                   if(mat[i][c]=='1')
                    {
                        bool f1 = false ,f2 =false;

                        for( j1 = c+1 ;j1 <col;j1++ )
                                if(mat[i][j1]=='0'){f1=true;break;}
                                else cnt1++;

                         for( j2 = c-1 ;j2 >=0;j2-- )
                                if(mat[i][j2]=='0'){f2=true;break;}
                                else cnt2++;

                        if( !f1 && !f2 )return -1; // No solution

                        if(f1 && !f2)ans +=cnt1 ;
                        else if(!f1 && f2) ans += cnt2;
                        else ans += min(cnt1,cnt2);

                    }
               }
    return ans;
}

int main()
{
   int t = II ,i,j;

   while(t--)
   {
       int ans = 0;
       row = II , col = II ;
       REP(i,row) scanf("%s",&mat[i]);
       int cost = inf;

       for(i=0;i<col;i++)
       {
            int sol = solveThisColumn(i);

            if(sol != -1)  cost = min (cost,sol);
       }
       CS;
       if(cost == inf )cout << -1 <<endl;
       else cout << cost << endl;
   }
}
