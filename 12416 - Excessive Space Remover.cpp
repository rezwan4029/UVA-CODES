#include <stdio.h>
#include <string.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
char s[5005555];
int main()
{
  while(gets(s))
  {
     int sp = 0 ;
     int need = 0 ;
     int len = strlen(s);
     for( int i = 0 ; i < len ; i++ )
     {
          if( s[i] == ' ') sp++;
          else 
          {
               need = max( need , sp );
               sp = 0 ;
          }
     }
     int ans = int(ceil( log2(need)));
    
     cout << ans << endl;
  }
}
