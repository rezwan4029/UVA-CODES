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
#define inf 1000000500
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

int main()
{
    string names[50],s1,s2;
    map<string,int>receive;
    map<string,int>given;
    int i,j,n,giv,cnt,cs=0;
    while(scanf("%d",&n)!=EOF)
    {
        receive.clear();given.clear();
        for(i=1;i<=n;i++){
            cin>>names[i];
            receive[ names[i] ] = given[ names[i] ] = 0;
        }
        for(i=1;i<=n;i++){
            cin>>s1;
            cin>>giv;
            cin>>cnt;
            if(cnt == 0 ) continue ;
            given[s1 ] += giv;
            int cost = 0;
            if(cnt!=0)
            {
                cost = giv/cnt;
                receive[ s1 ] += giv-(cnt*cost);
            }
            for(j=1;j<=cnt;j++)
            {
                cin>>s2;
                receive[s2] += cost;
            }
        }
        if(cs)cout<<endl;cs=1;
        for(i=1;i<=n;i++)
        {
            cout<<names[i]<<" "<< receive[ names[i] ] - given[ names[i] ] <<endl;
        }
    }
    return 0;

}
