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


int elements[1005],m,n;
bool path[1005];
int sol;
string solutions[1005];
set<string>mySet;
string toString(int number){ stringstream ss;ss << number; return ss.str(); }
bool cmp(int a,int b)
{
    return a>b ;
}
void printed(int k)
{
    string S="";
    int tempo[105],iNdx=0;
    for(int i=0 ;i <= k ; i++) if(path[i]) tempo[iNdx++]=elements[i];
    sort(tempo,tempo+iNdx,cmp);
    for(int i=0 ; i<iNdx ; i++)
    {
        if(i)S+='+';
        S+= toString( tempo[i] );
    }
    mySet.insert(S);
}
void solve(int s,int k,int r)
{

   path[k]=true;

   if(s + elements[k] == m)
   {
       printed(k) ;
       sol++;

   }

   else if( s+ elements[k] +  elements[k+1] <= m)
        solve( s+ elements[k], k+1, r- elements[k] );

   if( s+r-elements[k] >=m &&  s + elements[k+1]  <=m)
     {
      path[k]=false;
      solve(s,k+1,r- elements[k]);
     }
}

int main()
{
    int sum,i;
    while(1)
    {
        m= II ; n= II ;
        if(!m && !n) break;
        sum = 0 ;
        for(i=0;i<n;i++) sum+= elements[i] = II ;

        sort( elements, elements+n);
        printf("Sums of %d:\n",m);
        mySet.clear();
        sol = 0;
        if(sum < m ||  elements[0]>m) {
            printf("NONE\n");
            continue;
        }
        solve(0,0,sum);
        if(!sol) {
            printf("NONE\n");
            continue;
        }
        sol = 0 ;
        forstl(it,mySet) solutions[sol++] = *it ;
        for(i=sol-1 ; i>=0 ;i --)cout << solutions[i] <<endl;
    }
    return 0;
}

