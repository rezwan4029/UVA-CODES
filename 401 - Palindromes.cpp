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
#define CS printf("Case %d:\n",cs++)
#define PI 3.1415926535897932384626433832795
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define PII pair <int , int>


#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)

int cs=1;

int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
using namespace std;
char s[1005];
bool _cheCkm(char x ,char y)
{
    if(  x == 'O' && y == 'O'  ) return true ;
    if(  x == 'A' && y == 'A'  ) return true ;
    if(  x == 'H' && y == 'H'  ) return true ;
    if(  x == 'I' && y == 'I'  ) return true ;
    if(  x == 'M' && y == 'M'  ) return true ;
    if(  x == 'T' && y == 'T'  ) return true ;
    if(  x == 'U' && y == 'U'  ) return true ;
    if(  x == 'V' && y == 'V'  ) return true ;
    if(  x == 'W' && y == 'W'  ) return true ;
    if(  x == 'X' && y == 'X'  ) return true ;
    if(  x == 'Y' && y == 'Y'  ) return true ;
    if(  x == '1' && y == '1'  ) return true ;
    if(  x == '8' && y == '8'  ) return true ;
    if(( x == 'J' && y == 'L' )||( x == 'L' && y == 'J' ) ) return true ;
    if(( x == 'E' && y == '3' )||( x == '3' && y == 'E' ) ) return true ;
    if(( x == 'S' && y == '2' )||( x == '2' && y == 'S' ) ) return true ;
    if(( x == 'Z' && y == '5' )||( x == '5' && y == 'Z' ) ) return true ;

    return false ;
}
bool checkPalin(int j)
{
    for(int i=0; i<j ;i++ ,j--) if(s [ i ] != s[ j ]) return false;
    return true;
}
bool checkMirro(int j)
{
    for(int i=0; i<=j ;i++ ,j--) if( ! _cheCkm( s[i] , s[j] ) )return false;
    return true;
}
int main()
{
    bool MIRROR,PALIN  ;
    int len;

    while(scanf("%s",&s)==1)
    {
         len = strlen(s);

         PALIN  = checkPalin(len-1);
         MIRROR = checkMirro(len-1);


             if(  PALIN &&  MIRROR ) printf("%s -- is a mirrored palindrome.\n",s);
        else if(  PALIN && !MIRROR ) printf("%s -- is a regular palindrome.\n",s);
        else if( !PALIN &&  MIRROR)  printf("%s -- is a mirrored string.\n",s);
        else                         printf("%s -- is not a palindrome.\n",s);
    cout<<endl;
    }
    return 0;
}

