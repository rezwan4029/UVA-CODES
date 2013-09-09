#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )

int main()
{
   char msg[1010];
   int test , cs = 1 ;
   scanf("%d",&test);
   getchar();getchar();
   while(test--)
   {
      printf("Case #%d:\n",cs++);
      int len = 1 ;
      while(gets(msg))
      {
         int length = strlen(msg);
         if(  length == 0 ) break;
         string newStr = "";
         int currPos = 1 ;
         string s = "";
       
         for( int i = 0 ; i < length ; i++ )
         {
              
             if( msg[i] == ' ' || i == length -1)
             {
                 int L = newStr.length();
                 bool flag = false ;
                 for( int k = 0 ;k < L ; k++ )
                 {
                      if( k == currPos - 1 ) {
                          s += newStr[k];
                          flag = true;
                          break;
                      }
                 }
                 if( flag ) currPos++;
                 newStr = "";
             }
             else
             {
                 newStr += msg[i];
             }
         }
         cout << s << endl;
      }
      if(test) puts("");
      
   }
}
