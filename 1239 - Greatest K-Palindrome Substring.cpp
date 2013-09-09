#include <sstream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int dp[1004][1004];
string s;
int k;

int main()
{
    int T,i,j;

    scanf("%d",&T);
    while(T--)
    {
      cin>>s>>k;
      memset(dp,0,sizeof dp);
      int ans = 0;
      int len = s.size();
      for( int i = len ; i >=1 ; i--){
            for( j = i ; j <= len ; j++ ){
                    dp[i][j] = dp[i+1][j-1] +  (s[i-1] != s[j-1])  ; // mismatch mane kisu ekta kore palindrome banate hbe

                if(dp[i][j] <= k ) ans = max( ans , j-i+1 );
            }
      }
      cout<< ans << endl;
    }
}
