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


set<pdd>pnt;

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        int N = II ;
        rep(i,N){
            pdd p ;
            double x , y ;
            scanf("%lf %lf",&x,&y);
            pnt.insert( pdd(x,y) );
        }
        pdd ans = pdd(0,0);
        forstl(it,pnt){
            ans.first += it->first ;
            ans.second += it->second ;
        }
        ans.first /= double(N) ;
        ans.second /= double(N);
        bool flag = true ;
        forstl(it,pnt){
            double x = 2*ans.first - it->first ;
            double y = 2*ans.second - it->second ;
            if( pnt.find(pdd(x,y)) == pnt.end() ){
                flag = false ;
                puts("no");
                break;
            }
        }
        if(flag)puts("yes");
        pnt.clear();
    }
}
