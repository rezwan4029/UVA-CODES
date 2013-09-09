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
#include <sstream>
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64  long long
#define u64 unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define SS(s) scanf("%s",&s)
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL  ({i64  a; scanf(" %lld", &a); a;})
#define LU  ({u64  a; scanf(" %llu", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define PII pair <int , int>


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

int cs=1;
//

using namespace std;


#define Lim  100005
#define isprime(n) (a[n >> 4] & (1<<(((n)>>1)&7))) //works when n is odd
char a[Lim/16+2];

bool prime[Lim] ;

void seive()
{
    u64 i,j;
    msn(a,255);
    a[0]=0xFE;
    u64 sqRT=sqrt(Lim);
    for(i=1;i<sqRT;i++)
        if (a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1 ; j<(Lim>>1) ; j+=i+i+1)  a[j>>3]&=~(1<<(j&7));
    msn(prime,false);
    prime[ 2 ]= true;
    for(i=3;i<Lim;i+=2) if(isprime(i)) prime[ i ] = true ;
}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
int main()
{
    seive();
    string s ;
    while( cin >> s)
    {
        if( s== "0" ) break;
        int i,j,n = s.length();
        int ans = 2 ;
        REP(i,n){
            string x = "";
            for( j = 0 ; j < n && j < 6 ; j++ ){
                x+=s[i+j];
                int val = toInt(x);
                if( val > 100000 )break;
                if( prime[ val ] ){
                    ans = max( ans , val ) ;
                }
            }
        }
        cout << ans << endl;
    }

}
