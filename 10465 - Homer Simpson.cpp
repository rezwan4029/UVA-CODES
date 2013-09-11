/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

// Algo :

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

#define FOR(i,j,n) for(i=j;i<=n;i++)
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



int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
//

using namespace std;

int main()
{
    int m,n;i64 tot;
    while(cin>>m>>n>>tot)
    {
        int fix1,fix2;

        if(m>n)swap(m,n);
        fix1=tot/m;
        fix2=tot/n;
        int i,j;
        int burg=0,rest=inf;
        int ans=0;
        int f=0,k=0;

        for(i=0;i<=fix1;i++)
            for(j=0;j<=fix2;j++)
                {
                    i64 s=m*i+n*j;

                    if(s>tot)continue;

                    if(s==tot)
                    {
                        ans=max(ans,(i+j));
                        f=1;
                    }
                    else
                    {
                        if(rest>tot-s)
                        {
                            rest=tot-s;
                            burg=i+j;
                        }
                        if(rest==tot-s)
                        {
                                if(burg<i+j)
                                {
                                    burg=i+j;
                                }
                        }
                    }
                }
        if(f)printf("%d\n",ans);
        else
        {
            printf("%d %d\n",burg,rest);
        }
    }
    return 0;
}
