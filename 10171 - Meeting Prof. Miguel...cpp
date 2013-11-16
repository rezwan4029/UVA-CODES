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

const int MX = 27;
int n = 26 ,dY[MX][MX],dM[MX][MX];
int SY , SM ;
const int INF = 1000000000;

void Reset(){
    rep(i,n) {
        rep(j,n) dY[i][j] = dM[i][j] = INF ;
        dY[i][i] = dM[i][i] =  0 ;
    }
}

void _Warshall1(){
    rep(k,n)rep(i,n)rep(j,n){
            if(dY[i][j] > dY[i][k] + dY[k][j] ){
                dY[i][j] = dY[i][k] + dY[k][j] ;
            }
    }
}

void _Warshall2(){
    rep(k,n)rep(i,n)rep(j,n){
            if(dM[i][j] > dM[i][k] + dM[k][j] ){
                dM[i][j] = dM[i][k] + dM[k][j] ;
            }
    }
}

void build(int m)
{
    char road , dir , u , v ;   int cst ;
    while(m--)
    {
        getchar();
        cin >> road >> dir >> u >> v >> cst ;
        int x = u - 'A' ,  y = v - 'A' ;
        if( road == 'Y' )
        {
            if( dir == 'U' ) dY[x][y] = cst;

            else    dY[x][y] = dY[y][x] = cst;
        }
        else
        {
           if( dir == 'U' ) dM[x][y] = cst;

           else     dM[x][y] = dM[y][x] = cst;

        }
    }
    rep(i,n) dM[i][i] = dY[i][i] = 0;
    cin >> u >> v ;

    SY = u - 'A' , SM = v - 'A' ;
}

int main()
{

    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int M ;
    while ( cin >> M )
    {
        if( M == 0 ) break ;
        Reset();
        build(M);
        _Warshall1();
        _Warshall2();
        int ans = INF ;
        rep(i,n){
            if(dY[SY][i] == INF || dM[SM][i] == INF ) continue;
            if(dY[SY][i]+dM[SM][i] < ans ){
                ans = dY[SY][i]+dM[SM][i] ;
            }
        }
        if(ans == INF ) puts("You will never meet.");
        else
        {
            printf("%d",ans);
            rep(i,n)
                if(dY[SY][i] + dM[SM][i] == ans )
                    cout << " " << char( i + 'A' );
            puts("");
        }
    }
}
