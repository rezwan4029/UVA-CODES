/*
    Royal Flush , AUST
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
typedef vector<int> vi;
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const int SZ = 203 ;
const int  mod = 1000000007 ;

ll nCr[SZ][SZ] ;
ll dp[52][SZ];
bool Vis[52][SZ];

ll solve(int color , int box ){
    if(color > box || color <= 0  || box <= 0  )return 0 ;
    if( color == 1 ) return 1 ;
    ll &ret = dp[color][box];
    if(Vis[color][box])return ret ;
    Vis[color][box] = true ;
    ret = 0 ;
    For(i,box){
        ret = ( ret + ( nCr[box][i] * solve(color-1,box-i) ) % mod ) %mod ;
    }
    return ret;
}

bool ansGen[22][22][52];
ll ans[22][22][52];

int main() {
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    nCr[0][0] = 1;
	For(i,SZ-1)
	{
		nCr[i][0] = 1;
        For(j,i) nCr[i][j] = ( nCr[i-1][j-1] + nCr[i-1][j] ) % mod;
	}
    int t = II;
    For(cs,t){
        int r = II + 1  , c = II + 1 ,k = II ;

        if(ansGen[r][c][k]){
            printf("Case %d: %d\n",cs,ans[r][c][k]);
            continue ;
        }

        ansGen[r][c][k] = true ;

        if( r == 1  && c == 1 ){
            printf("Case %d: %d\n",cs,k);
            ans[r][c][k] = k ;
            continue;
        }
        int even = (r*c) / 2 ;
        int odd = (r*c) - even;
        ll tmp , ret = 0;
        For(j,k)For(i,k-j) {
            tmp = nCr[k][j] ;
            tmp = ( tmp * nCr[k-j][i] ) %mod ;
            tmp = ( tmp * solve(j,even) ) % mod ;
            tmp = ( tmp * solve(i,odd) )% mod ;
            ret = ( ret + tmp ) % mod;
        }
        ans[r][c][k] = ret ;
        printf("Case %d: %lld\n",cs,ret);
    }
}
