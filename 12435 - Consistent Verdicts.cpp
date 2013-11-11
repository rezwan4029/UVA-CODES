#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define sq(a) ((a)*(a))
pair<int,int> P[1002];
int d[1002*1002];
int main()
{
    int test ,cs = 1;

    cin >> test ;

    while(test--)
    {
        int n , sz = 0;

        cin >> n ;
        

        REP(i,n) cin >> P[i].first >> P[i].second ;
        
        if(n == 1 ) {
            printf("Case %d: 1\n",cs++);
            continue ; 
        }
        
        
        for(int i = 0 ; i < n ; i++)
                for( int j = i+1 ; j < n ; j++ )
                    d[sz++] = sq( P[i].first - P[j].first) + sq( P[i].second - P[j].second) ;

        sort(d,d+sz);

        int ret  = 2 ;

        for( int i = 1 ; i < sz ; i++ ) ret += ( d[i] != d[i-1]);
        
        printf("Case %d: %d\n",cs++, ret  );
    }

}
