#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#define INF 1<<30
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++ )
#define forstl(i,n) for(__typeof(n.begin()) i = n.begin() ; i != n.end() ; i++)
typedef  long long int ll;


#define MAXN 100005

ll A[MAXN], L1[MAXN],L2[MAXN];
int n ;

void LIS()
{
    vector<ll>temp;
    temp.push_back(-INF);
    rep(i,n) temp.push_back(INF);

    int lis = 0 ;

    rep(i,n)
    {
        int low = lower_bound(temp.begin(),temp.end(),A[i])- temp.begin();
        temp[ low ] = A[ i ] ;
        lis = max(lis,low);
        L1[i] = lis ;
    }
}
void LDS()
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
        L2[i] = lds ;
    }
    reverse(L2,L2+n);
}

int main()
{
  while(scanf("%d",&n)==1)
  {
      rep(i,n) scanf("%lld", &A[i]);
      LIS();
      LDS();
      ll ans = 0 ;
      rep(i,n) ans = max( ans , min(L1[i],L2[i]) );
      printf("%lld\n",ans*2 - 1);
  }
  return 0;
}
