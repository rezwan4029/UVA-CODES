#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )

int main()
{
  int test ;
  scanf("%d",&test);
  while(test--)
  {
    int w ,x, n , MIN = 0 , MAX = 0 ;
    scanf("%d %d",&w,&n);
    rep(i,n)
    {
      scanf("%d",&x);
      MIN = max( MIN , min( x , w - x) );
      MAX = max( MAX , max(  x ,w -x ) );
    }
 
    cout << MIN << " " << MAX << endl;
  }
}
