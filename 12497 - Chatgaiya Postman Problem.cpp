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
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

int N , M ;

ll dp[13][1<<13][2][2];
bool Vis[13][1<<13][2][2];
bool mat[20][20];
int startNode ;

ll solve(int currNode , int masK , bool isLastStart , bool isVisStart){
    if(isVisStart && currNode == startNode ) return 1 ;
    
    ll &ret = dp[ currNode ][ masK ][ isLastStart ][ isVisStart ];
    if(      Vis[ currNode ][ masK ][ isLastStart ][ isVisStart ] ) return ret ;
             Vis[ currNode ][ masK ][ isLastStart ][ isVisStart ] = true ;
    
    ret = 0 ;
    rep(i,N){
        if(mat[currNode][i] == false ) continue ;
        if( i == startNode ){
            if(isLastStart) continue ;
            ret += solve( i , masK , false , isVisStart ) ;
        }
        else{
            if(masK & (1<<i) ) continue ;
            bool flag = ( currNode == startNode ) ;
            ret += solve( i , masK | (1<<i) , flag , isVisStart || ( flag && ( masK != ( 1 << startNode ) )  )  ) ;
        }
    }
    return ret ;
}

int main(){
    int t = II ;
    For(cs,t){
        scanf("%d %d",&N,&M);
        ms(mat,false) ;
        rep(i,M){
            int x = II  , y = II  ;
            mat[x][y] = mat[y][x] = true ;
        }
        ll nDumbles = 0 ;
        rep(i,N){
            ms(Vis,false);
            startNode = i ;
            nDumbles += solve( i , 1 << i , false , false ) ;
        }
        printf("Case %d: %lld\n",cs , nDumbles/8);
    }
}
