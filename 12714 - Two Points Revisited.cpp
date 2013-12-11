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

int main(){
    int t = II;
    For(cs,t){
        int x1 = II , y1 = II , x2 = II , y2 = II;
        if(x1 > x2 || (x1 == x2 && y1>y2) ) swap(x1,x2),swap(y1,y2);
        int difx = abs(x1-x2),dify = abs(y1-y2);
        printf("Case %d: ",cs);
        if(y1 <= y2){
            int Max = max(x1,max(x2,max(y1,y2)));
            int x = Max,y = 0;
            printf("%d %d %d %d\n",x,y,x-dify,y+difx);
        }
        else{
            int x = 0,y = 0;
            printf("%d %d %d %d\n",x,y,x+dify,y+difx);
        }
    }
}
