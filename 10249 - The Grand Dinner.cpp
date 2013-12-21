/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 77 ;
const int INF = 1e8 + 7;

vi Ans[ MX ];
int m , n ;// team , table

struct ss {
    int id , sz ;
}table[MX];

int team[MX];

bool cmp(ss a , ss b){
    return a.sz > b.sz ;
    if( a.sz == b.sz ) return a.id < b.id ;
}

bool fnc()
{
    For(i,m) {
            sort(table+1,table+n+1,cmp);

            For(j,team[i]) {

                if( table[j].sz > 0 ) {
                    table[j].sz--;
                    Ans[ i ].pb( table[j].id  );
                    continue ;
                }

                return false ;
            }
    }
    return true ;
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif

    while( scanf("%d %d",&m,&n) ){
        if( n == 0 && m == 0 ) break ;
        bool ok = true ;
        For(i,m) {
            team[i] = II ;
            if( team[i] > n ) ok = false ;
        }
        For(i,n)  table[i].sz = II , table[i].id = i ;

        if( !fnc() || !ok ) puts("0");

        else {
            puts("1");
            for( int i = 1 ; i <= m ; i++ ){
                int len = Ans[i].size();
                sort( all(Ans[i])  );
                rep(j,len)
                {
                    if( j ) printf(" ");
                    printf("%d",Ans[i][j]);
                }
                puts("");
            }
        }
        For(i,m) Ans[i].clear() ;
    }
}
