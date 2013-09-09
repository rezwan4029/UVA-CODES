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
#define EPS 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({i64 a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795

#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)

int cs = 1;

//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;

int main()
{
    int n,T,i;
    while(cin >> n >> T)
    {
        vector<DB>res;
        DB x = 0 ,y = 0 ;
        REP(i,n)
        {
           int r = II , t = II ;
           DB theta = 2.00 * PI * DB(T)/DB(t);
           x += DB(r) * cos(theta);
           y += DB(r) * sin(theta);
           DB ans = sqrt( x*x + y*y ) ;
           res.pb(ans+EPS);
        }
        REP(i,n){
            if(i)printf(" ");
            printf("%.4lf",res[i]);
        }
        puts("");
    }
    return 0;
}



