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
#define pi acos(0.0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 205 ;
char grid[MX][MX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void dfs(int x , int y , char c){
    grid[x][y] = c ;
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( grid[nx][ny] == ' ' ) dfs(nx,ny,c);
    }
}

int main()
{
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int n = -1 ;
    while(gets(grid[++n]) != NULL )
    {
        if(grid[n][0]!='_') continue;
        rep(i,n)
            for(int j = 0 ; grid[i][j] ; j++)
                if(grid[i][j] != 'X' && grid[i][j] != ' '){
                    dfs(i,j,grid[i][j]);
                }
        rep(i,n+1)   puts(grid[i]);
        n = -1 ;
    }
}
