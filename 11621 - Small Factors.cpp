#include <bits/stdc++.h>

using namespace std;

typedef long long Long ;

const Long MX = 2147483648LL ;

vector< Long > V ;

int main(){
    for( int i = 0 ; ;i++){
        Long x = pow(2,i) ;
        if( x > MX ) break ;
        for( int j = 0 ; ; j++) {
            Long y = pow(3,j);
            if( x * y > MX ) break ;
            V.push_back( x * y ) ;
        }
    }
    V.push_back( (1LL << 31 ) * 3 ) ;
    sort( V.begin() , V.end() );
    unique( V.begin() , V.end() );
    Long N ;

    while( scanf("%lld",&N) and N ) {
        Long Ans = *lower_bound( V.begin() , V.end() , N )  ;
        printf("%lld\n",Ans);
    }
}
