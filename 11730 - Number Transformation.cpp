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

int cs=1;

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

int A,B;
#define Lim 1005
#define isprime(n) (a[n >> 4] & (1<<(((n)>>1)&7))) //works when n is odd
char a[Lim/16+2];
int prime[Lim];

void seive()
{
    int i,j,len=0;
    msn(a,255);
    a[0]=0xFE;
    int sqRT=sqrt(Lim);
    for(i=1;i<sqRT;i++)
        if (a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1 ; j<(Lim>>1) ; j+=i+i+1)  a[j>>3]&=~(1<<(j&7));
    prime[len++]=2;
    for(i=3;i<Lim;i+=2) if(isprime(i)) prime[len++]=i;
}

int dp[1005];
int solve(int now)
{
    if(now==B)return 0;
    int &ret=dp[now];
    if(ret!=-1)return ret;
    ret=inf;
    for(int item=0;prime[item]<=(now/2);item++)
            if(now%prime[item]==0 && prime[item]+now<=B)
                    ret=min(ret,solve(now+prime[item])+1);
    return ret;
}
int main()
{
    seive();
    while(A=II,B=II)
    {

        if(A+B == 0 ) return 0 ;
        msn(dp,-1);
        CS;
        int ans=solve(A);
        if(ans!=inf)cout<<ans<<endl;
        else    cout<<-1<<endl;
    }
    return 0;
}
