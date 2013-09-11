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

#define FOR(i,n) for(__typeof(n)i=1;i<=n;i++)
#define REP(i,n) for(__typeof(n)i=0;i<n;i++)
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
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
//
int cs = 1;
using namespace std;

#define mx 102

int Histogram(int Hist[],int n)
{
        int Left[mx],Right[mx];
        Hist[0] = Hist[n+1] =  -1;
        int cnt , x , ans = 0 ;
        FOR(i,n)
        {
            x = i+1;
            cnt = 0;
            while(Hist[x]>=Hist[i])x++ , cnt++ ;
            Right[i] = cnt ;

            x = i-1;
            cnt = 0;
            while(Hist[x]>=Hist[i])x-- , cnt++ ;
            Left[i] = cnt ;

            ans = max( ans , (Left[i] + Right[i] +1 )* Hist[i] ) ;
        }
        return ans ;
}
int m[mx][mx];
int  H[mx];

int main()
{
    while(true)
    {
        int r = II , c = II ;
        if( r + c == 0 ) break;
        REP(i,r) REP(j,c) cin >> m[i][j];

        int res = 0 ;

        ms0(H);

        REP(i,r)
        {
            REP(j,c) m[i][j] == 1 ? H[j+1] = 0 : H[j+1] += 1 ;

            res = max( Histogram(H,c) , res );
        }

        cout << res << endl ;
    }
}
