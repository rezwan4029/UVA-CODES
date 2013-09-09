#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int n;
int dp1[1002][1002];
int ispalindrome(int i,int j)
{
    if( i >= j ) return 1 ;
    int &ret = dp1[i][j];
    if(ret != -1 ) return ret;
    ret = 0 ;
    if( s[i] == s[j] ) ret = ispalindrome( i +1 , j -1 ) ;
    return ret ;
}
int dp2[1001];
int solve(int curr)
{
  if( curr >= n ) return 0 ;
  int &ret = dp2[curr];
  if( ret != -1 ) return ret ;
  ret = 99999;
  for( int i = curr ;  i < n  ; i++ ){
           if( ispalindrome(curr,i)){
               ret = min( ret , solve(i+1) +1) ;
           }
  }
  return ret ;
}
int main()
{
    int t;
    cin >> t ;
    for( int cs = 1 ; cs <= t ; cs++ ){
            cin >> s ; 
            n = s.length();
            memset(dp1,-1,sizeof dp1);
            memset(dp2,-1,sizeof dp2);
            int ret = solve(0);
            printf("%d\n",ret);
    }       
}
