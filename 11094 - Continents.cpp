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

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 25;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char g[MX][MX];
bool Vis[MX][MX];
int r , c ;

int Cnt ;
char color;
void dfs(int x , int y ){
    Vis[x][y] = true ;
    Cnt++;
    rep(i,4) {
        int nx = x + dx[i]  ;
        int ny = y + dy[i]  ;
        if( ny < 0 ) ny = c - 1 ;
        if( ny >= c ) ny = 0 ;
        if( nx >= 0 && nx < r && !Vis[nx][ny] && g[nx][ny] == color ) dfs(nx,ny);
    }
}
int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    bool blank = false ;
    while( scanf("%d %d",&r,&c) != EOF ){
        //if( blank ) puts(""); blank = true ;
        rep(i,r) scanf("%s",g[i]);
        ms(Vis,false);
        int Ans = 0 , x = II , y = II ;
        color = g[x][y];
        dfs(x,y);
        Cnt = 0 ;
        rep(i,r)rep(j,c)if(!Vis[i][j] && g[i][j] == color ){
            Cnt = 0 ;
            dfs(i,j);
            Ans = max(Ans,Cnt);
        }
        printf("%d\n",Ans);
    }
}
