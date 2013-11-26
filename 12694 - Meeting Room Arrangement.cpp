/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const double INF = 1000000;

struct activity{
  int st,end;
} act[110];

int cnt ;

void solve(int i,int j)
{
   int m = i + 1 ;
   while(m <= j && act[m].st <act[i].end) m++;
   if(m<j){
         cnt++;
         solve(m,j);
   }
}
bool cmp(activity a , activity b ){
    if( a.end == b.end  ) return a.st < b.st ;
    return ( a.end < b.end );
}

int main(){
    //freopen("in.txt","r",stdin);
    int t = II  , n ;
    while( t-- ) {
        int n = 0 ;
        while(1) {
            int x = II , y = II ;
            if( !x && !y )break;
            act[n].st = x , act[n].end = y ;
            n++;
        }
        sort(act,act+n,cmp);
        cnt = 1 ;
        solve(0,n);
        printf("%d\n",cnt);
    }
}
