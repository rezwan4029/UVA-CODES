/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
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

struct argus{
    int Num , period , time ;
    argus(int _n , int _p , int _t){
        Num = _n , period = _p , time = _t ;
    }
    bool operator < ( const argus &x ) const{
        if( period == x.period ) return Num > x.Num ;
        return period > x.period ;
    }
};
int main(){
    string cmd ;
    priority_queue<argus>Que;
    while( cin >> cmd ){
        if ( cmd == "#" ) break ;
        int Q = II , prd = II ;
        Que.push( argus(Q,prd,prd) );
    }
    int k = II ;
    while( k-- ){
        argus u = Que.top() ; Que.pop();
        printf("%d\n",u.Num);
        u.period += u.time ;
        Que.push(u);
    }
}
