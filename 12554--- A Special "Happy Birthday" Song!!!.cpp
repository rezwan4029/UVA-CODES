#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  string H[]={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"};
  string s[105];
  while( scanf("%d",&n)==1)
  {
      for( int i = 0 ; i < n ; i++ )cin>>s[i];
      int cnt ;
      if(n<=16) cnt =1;
      else if(n<=32)cnt = 2;
      else if(n<=48)cnt = 3;
      else if(n<=64)cnt = 4;
      else if(n<=80)cnt = 5;
      else          cnt = 6;
      int k = 0;
      for(int i = 0 ; i < cnt ; i++ ){

            for(int j = 0 ; j < 16 ; j++){
                cout<<s[ (k%n)  ]<<": "<<H[j]<<endl;
                k++;
            }
      }


  }

}
