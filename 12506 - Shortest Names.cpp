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
#define LL ({i64 a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795


#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)

int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);

int cs = 1;
//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//
using namespace std;

int main()
{
    int T = II ,i,j,L1,L2;
    string s[1005] ,x ,y ;
    int largest[1005];
    while(T--){
        int n = II ;
        REP(i,n) cin >> s[i] ,largest[i] = 1;
        sort(s,s+n);

        int ans = 0;
        REP(i,n-1){
            x = s[i] ;
            y = s[i+1];
            L1 = x.length(); L2 = y.length();
       //     cout << x <<"  "<< y <<"   "<< L1<<"    " << L2 <<endl;
            L1 = min( L1, L2 );

            int counts = 1 ;
            REP(j,L1) if( x[j] != y[j] )break; else counts++;

            largest[i]   = max( counts ,largest[i] );
            largest[i+1] = max( counts ,largest[i+1] );
           // cout << counts <<endl;
        }
        //debug_arr(largest,n);
        REP(i ,n) ans += largest[i];
        printf("%d\n",ans);

    }
    return 0;
}
