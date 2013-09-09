/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<queue>
#define pb push_back
#define INF 1<<30
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

#define MAXN 100007
int A[MAXN],n;

int LDS()
{
    reverse(A,A+n);
    vector<ll>temp;
    temp.push_back(-INF);
    rep(i,n) temp.push_back(INF);
    int lds = 0 ;
    rep(i,n)
    {
        int low = lower_bound(temp.begin(),temp.end(),A[i])- temp.begin();
        temp[ low ] = A[ i ] ;
        lds = max(lds,low);
      //  L2[i] = lds ;
    }
   // reverse(L2,L2+n);
   return lds;
}
int main()
{
    int x ,cs = 1;
    bool p = false;
    while(scanf("%d",&A[0]) && A[0] != -1 )
    {
        n  = 1 ;
        while(1){
            scanf("%d",&x);
            if(x == -1 )break;
            A[n++] = x ;
        }
        if(p)puts(""); p = 1 ;
        printf("Test #%d:\n",cs++);
        printf("  maximum possible interceptions: %d\n",LDS());
        ms(A,0);
    }
}
