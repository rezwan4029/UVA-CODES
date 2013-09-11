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

struct cmm{ int talk, time; }J[1005];

bool cmp(cmm a , cmm b)
{
    return a.time > b.time ;
}

int main()
{
  int n ,cs = 1;
  while(cin >> n && n )
  {
        rep(i,n) cin >> J[i].talk >> J[i].time;

        sort(J,J+n,cmp);

      //  rep(i,n) cout << J[i].talk << "   "<< J[i].time << endl ;

      int mx  = 0 , sum = 0 ;

      rep(i,n){
          sum += J[i].talk ;
          mx = max( mx , sum + J[i].time );
      }
      printf("Case %d: %d\n",cs++,mx);
  }
}
