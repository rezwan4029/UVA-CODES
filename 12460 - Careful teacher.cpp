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
#define debug_arr(x,n){for(int i=1;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;
map<string,bool>myBook;
int len ;
bool check(string p,string q)
{
    for(int i = len-1 ; i>= 0 ; i--){

        if(p[i] == q[i] )continue;

        q[i] = p[i];

        if( myBook[q] != true) return false;
    }
    return true;

}
int main()
{
    int i,j;

  //  myBook.clear();
    char  s[105],x[105],tmp[105];
    while(scanf("%s",&s))
    {
        if(s[0] == '-') break;
        myBook[s] = true;
        memcpy(tmp,s,sizeof s);
    }
    len = strlen(tmp);
    while( scanf("%s %s",&s,&x) ==2 )
    {
        if( myBook[x] != true) puts("No");
        else {

            bool ans = check(s,x);
            if(ans == true )puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
