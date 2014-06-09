#include<bits/stdc++.h>
using namespace std;
typedef long long Long ;
typedef pair<Long,Long>pii;
vector< Long > Ans;

/**
    Your are given two integers a and b. You have to find all the primes within range a and b.
    Here, 1 ≤ a ≤ b ≤ 2^31-1 and b - a ≤ 10^6.
    Note: You have to handle 1, 2 and even numbers for appropriate case of your own.
*/

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 1000032

unsigned base[MAX/64], seg[RNG/64], pr[LEN];

#define chkC(x,n) (x[n>>6] & (1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6] |=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve()
{
    unsigned i, j, k;
    for(i = 3; i < LMT ; i += 2 )
        if( !chkC(base, i) )
            for( j = i*i , k = i<<1; j < MAX ; j += k ) setC(base, j);
    for(i = 3, j = 0 ; i < MAX; i += 2 ) if( !chkC(base, i) ) pr[j++] = i;
}

/* Returns the prime-count within range [a,b] and marks them in segment[] */
int segmented_sieve(Long a , Long b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if( b < 2 ) return 0;
    if( a <= 2 ) Ans.push_back( 2 );
    if( a < 3 ) a = 3;
    if( a % 2 == 0 ) a++;
    memset(seg,0,sizeof seg);
    for( i = 0 ; pr[i] * pr[i] <= b; i++) {
        j = pr[i] * ( ( a + pr[i]-1) / pr[i] );
        if( j % 2 == 0 ) j += pr[i];
        for(k = pr[i]<<1 ; j <= b; j += k )
            if( j != pr[i] ) setC(seg, (j-a));
    }
    for(i = 0 ; i <= b - a ; i += 2 )
        if( !chkC(seg,i) ){
            cnt++;
            Ans.push_back( i + a );
        }
    return cnt;
}

int main(){
    sieve();
    Long a , b ;
    while( scanf("%lld %lld",&a,&b) != EOF ){
        Ans.clear();
        segmented_sieve( a , b );
        Long mn = 1e18 , mx = 0 ;
        pii r1 , r2 ;
        int tot = Ans.size();
        if( tot <= 1 ){
            puts( "There are no adjacent primes." );
            continue;
        }
        for( int i = 0 ; i < tot - 1 ; i++ ){
            Long d = Ans[i+1] - Ans[i];
            if( d > mx ){
                mx = d ;
                r2 = make_pair( Ans[i] , Ans[i+1] );
            }
            if( d < mn ){
                mn = d ;
                r1 = make_pair( Ans[i] , Ans[i+1] );
            }
        }
        printf( "%lld,%lld are closest, %lld,%lld are most distant.\n",r1.first,r1.second,r2.first,r2.second );
    }
}
