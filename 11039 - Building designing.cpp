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
#define mx  1000007
#define pi 3.1415926535897932384626433832795

int red[mx] , blue[mx];

int solve(int *R , int r , int *B , int b)
{

    if(r == 0 || b == 0 ) return 0 ;

    B[b] = R[r] = 999999 +10 ;
    int off = 999999 + 10 ;
    b++,r++;
    int ans = 0 ;
    int now = B[0];
    bool f = true ;
    while(true)
    {
       ans++ ;
       int pos ;
       if(f)
       {
         pos = *upper_bound(R,R+r,now);
         now = pos ;
         f = !f ;
         if(pos == off )break;
       }
       else
       {
         pos = *upper_bound(B,B+b,now);
         now = pos ;
         f = !f ;
         if(pos == off )break;
       }
    }
    return ans ;
}

int main()
{
    int test ;

    cin >> test ;

    while(test--)
    {
        int n , x , r = 0 , b = 0 ;

        cin >> n ;

        For(i,n){
            cin >> x ;
            if( x > 0 ) red[ r++ ] = x ;
            else blue[ b++ ] = -x ;
        }
        sort(red,red+r);
        sort(blue,blue+b);

        int ans = 0;

        if(red[0] > blue[0] ) ans = solve(red,r,blue,b);
        else  ans = solve(blue,b,red,r);

        cout << ans << endl;

    }
}
