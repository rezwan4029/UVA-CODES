#include <stdio.h>
#include <string.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
  int cs = 1 ;
  int n , m , c ;
  map<int,bool>now;
  int cap[22];
  while( cin >> n >> m >> c )
  {
    if( n+m+c == 0 ) break;
    now.clear();
    for( int i = 1 ; i <= n ; i++ ) cin >> cap[i];
    int mxTolerance = 0 , curr = 0 ;
    while(m--)
    {
       int x ;
       cin >> x ;
       if( now[x] == false)
       {
           now[x] = true;
           curr += cap[x];
       }
       else
       {
           now[x] = false;
           curr -= cap[x];
       }
       mxTolerance = max( curr , mxTolerance );
    }
    printf("Sequence %d\n",cs++);
    if( mxTolerance > c )
    {
        puts("Fuse was blown.\n");
    }
    else
    {
        puts("Fuse was not blown.");
        printf("Maximal power consumption was %d amperes.\n\n",mxTolerance );
    }
  }
}
