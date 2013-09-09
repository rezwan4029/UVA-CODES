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
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 10109999990
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


#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)


int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//
int cs = 1;
using namespace std;

int main()
{
    DB W,H,a,b;
    while(scanf("%lf : %lf",&a,&b) != EOF )
    {
       DB otivuj = sqrt( a*a + b*b ) ;
       DB radius = otivuj / 2.00 ;
       DB angle  = atan( b / a ) ;

       DB high = 10000 , low = 0.0 ,mid;

       for(int it = 0 ;it < 50 ;it ++ )
       {

            mid =  (high+low)/2.00 ;

            DB peri = 4.00* radius*angle*mid + a*mid*2.00;

            if( peri > 400) high = mid;
            else            low  = mid;

       }
       CS;printf("%.10lf %.10lf\n",a*mid + eps ,b*mid + eps );

    }
    return 0;
}
