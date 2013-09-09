/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<queue>
#define pb push_back
#define INF 1<<30
#define CS printf("Case #%d: ",cs++)
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
#define PI 3.1415926535897932384626433832795
using namespace std;
typedef  long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

int main()
{
    int test = II ;
    string str;
    For(cs,test){
       cin >> str ;
       int have[207] = {0};
       int len = str.length();
       rep(i,len)have[ str[i] ]++;
       int ans  = 0 ;
       while( true ){
              if(  have[ 'M' ] - 1 >= 0 ) have[ 'M' ]-=1;
              else break;
              if(  have[ 'A' ] - 3 >= 0 ) have[ 'A' ]-=3 ; 
              else break;
              if(  have[ 'R' ] - 2 >= 0 ) have[ 'R' ]-=2 ;
              else break;
              if(  have[ 'G' ] - 1 >= 0 ) have[ 'G' ]-=1;
              else break;
              if(  have[ 'I' ] - 1 >= 0 ) have[ 'I' ]-=1;
              else break;
              if(  have[ 'T' ] - 1 >= 0 ) have[ 'T' ]-=1;
              else break;
              ans++; 
       } 
       printf("%d\n",ans);
    }
}
