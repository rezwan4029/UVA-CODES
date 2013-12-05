/*
Rezwan_4029
AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll a; scanf("%lld", &a); a;})
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

#define forab(i, a, b) for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n) forab (i, 0, (n) - 1)
#define For(i, n) forab (i, 1, n)
#define rofba(i, a, b) for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n) rofba (i, 0, (n) - 1)
#define rof(i, n) rofba (i, 1, n)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 107;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int r , c ;
char g[MX][MX];
int cnt ;
char pixel ;
void dfs(int x , int y){
    g[x][y] = '#' ;
    cnt++;
    rep(i,8){
        int nx = dx[i] + x ;
        int ny = dy[i] + y ;
        if( nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] == pixel ) dfs(nx,ny);
    }
}
int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    while( scanf("%d %d",&r,&c) ){
        if( r == 0 && c == 0 ) break ;
        rep(i,r) scanf("%s",g[i]);
        int Star = 0 ;
        rep(i,r)rep(j,c)if(g[i][j] != '#'){
            pixel = g[i][j];
            cnt = 0 ;
            dfs(i,j);
            Star += ( pixel == '*' && cnt == 1 );
        }
        printf("%d\n",Star);
    }
}
