#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#define inf ~(1<<31)
#define ms(a,x) memset(a,x,sizeof a)
#define sqr(a) ((a)*(a))
using namespace std;
#define rep(i,n) for(__typeof(n) i = 0 ; i < n ; i++)
#define For(i,n) for(__typeof(n) i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin()) i = 0 ; i != n.end() ; i++)
typedef long long ll;
#define mod 1000000007
#define mx  20000 + 5
int dragon[mx] , knight[mx];

int main()
{
    int d , k ;

    while(cin >> d >> k )
    {
        if( d == 0 && k == 0 ) break ;

        For(i,d) cin >> dragon[i] ;
        For(i,k) cin >> knight[i] ;

        sort(dragon+1,dragon+d+1);
        sort(knight+1,knight+k+1);


        int cost = 0 ;

        if(d > k ) {
            puts("Loowater is doomed!");
            continue;
        }

        int pos = 1 ;

        For(i,k){
            if( knight[i]>=dragon[pos] ) {
                pos++ ;
                cost += knight[i] ;
            }
            if(pos > d ) break;
        }
        if(pos > d ) cout << cost << endl;
        else puts("Loowater is doomed!");
    }

}
