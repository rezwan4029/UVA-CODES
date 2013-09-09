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
#define CS printf("Case #%d: ",cs++)
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
#define PI 3.1415926535897932384626433832795
using namespace std;
typedef  unsigned long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

int cs = 1 ;

ll sum[307] = {0};

ll solve(ll n){
   if( n < 301 ) return sum[n];
   ll ans = 0 ;
  // ll pos  = 0 ;
  // int cnt = 0 ;
  // while( pos + 300 <= n ) pos += 300, ans += sum[300] , cnt++ ;
   
   ll temp = n / 300 ;
 /*  puts("_________");
   cout << cnt << "   " << temp << endl;
   cout << temp * 300  << "   " << pos << endl;
   */
   ans = sum[300] * temp ;
   
   ans += sum[ n - ( temp * 300 ) ] ;
   return ans ; 
}
int main()
{
   ll F[307];
   
   F[1] = F[2] = 1 ;
   sum[1] = 1 ; sum[2] = 2 ;
   forab(i,3,300) F[i] = ( F[i - 1 ] + F[i - 2 ] ) % 100  , sum[i] = sum[i-1] + F[i] ;
   //For(i,302) cout << F[i] << " , ";
   int test = II ;
   For(cs,test){
       ll a , b ;
       scanf("%llu %llu",&a,&b);
       ll ans = solve( b ) - solve(a - 1 );
       printf("%llu\n",ans);
   }
}
