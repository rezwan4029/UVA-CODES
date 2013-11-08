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

struct schedule{
    ll st , en , time ;
};

schedule a[100008];

bool cmp(schedule x , schedule y )
{
    return x.time < y.time ;
}

int main()
{
    int N ;
    while( scanf("%d",&N) && N )
    {
        rep(i,N)
        {
            scanf("%lld",&a[i].st);
            scanf("%lld",&a[i].en);
            a[i].time = a[i].st + (a[i].en - a[i].st )/2+1  ;
        }
        sort(a,a+N,cmp);
        ll Curr = -1 ;
        bool Ok = true ;
        rep(i,N)
        {
            Curr = max( Curr , a[i].st ) + (a[i].en - a[i].st )/2+1 ;
            if(Curr > a[i].en ){
                Ok = false ;
                break ;
            }
        }
        printf("%s\n",Ok?"YES":"NO");
    }
}
