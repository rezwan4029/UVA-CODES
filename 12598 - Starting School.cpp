#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)


#define SZ  50005
typedef long long ll ;

ll given[SZ];
ll gap[SZ];
ll sorted[SZ];

int main()
{
    int test ,cs = 1; scanf("%d",&test);

    while(test--)
    {
        ll n , K ,q ;
        scanf("%lld %lld %lld",&n,&K,&q);

        For(i,K) {
            scanf("%lld",&given[i]);
            sorted[i] = given[i];
            gap[i] = 0;
        }
        sorted[ K + 1 ] = n + 1 ;
        
        sort(sorted,sorted+K+2);

        gap[0] = sorted[1] - sorted[0] - 1;
        
        For(i,K){
            gap[i] = sorted[i+1] - sorted[i] + gap[i-1] -1 ;
        }
/*

        puts("Sorted...");
        for(int i = 0 ; i < K ; i++ ) cout << given[i] << "  ";
        puts("");



        puts("Gaps....");
        for(int i = 0 ; i < K -1 ; i++ )cout << gap[i] << "  ";
        puts("");

*/


        printf("Case %d:\n",cs++);

        while(q--){

             ll pos ; scanf("%lld",&pos);

             if(pos <= K ) {
                    printf("%lld\n",given[pos]);
                    continue ;
             }

             ll now = pos - K  ;

             int low = lower_bound(gap,gap+K+1,now)-gap;
             
             now -= gap[ low  - 1 ] ;
             
             //cout << "now...."<< now << "   gap .." << z <<endl;
            
             printf("%lld\n", sorted[ low ] + now ) ;
        }
    }
}
