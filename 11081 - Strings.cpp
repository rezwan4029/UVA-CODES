/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const int mod = 10007 ;

int dp[62][62][62][2];
bool Vis[62][62][62][2];

string a , b , c ;
int la , lb , lc ;

int solve(int i , int j ,int k , bool which ){

    //if( k > lc ) return 0 ;
    if(k == lc ) return 1 ;

    if( i >= la && j >= lb ){
        return 0;
    }

    int &ret = dp[i][j][k][which];
    if( Vis[i][j][k][which] )return ret ;
    Vis[i][j][k][which] = true ;

    ret = 0 ;

    if(which)
    {
        if(a[i] == c[k] ){
            ret = ( ret + solve(i+1,j,k+1,!which) ) %mod ;
            ret = ( ret + solve(i+1,j,k+1,which) ) %mod ;
        }
        if( i < la ) ret =   ( ret + solve(i+1,j,k,which) ) %mod ;
    }
    else
    {
        if(b[j] == c[k] ){
            ret = ( ret + solve(i,j+1,k+1,!which) ) %mod ;
            ret = ( ret + solve(i,j+1,k+1,which) ) %mod ;
        }
        if( j < lb ) ret =   ( ret + solve(i,j+1,k,which) ) %mod ;
    }

    return ret % mod ;
}

pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<int, pair<int, int> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}

int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

int main(){
    int t = II ;
    For(cs,t){
        cin >> a >> b >> c ;
        la = a.size() , lb = b.size() , lc = c.size() ;
        ms(Vis,false);
        int ret = ( solve(0,0,0,true) + solve(0,0,0,false) ) % mod ;
        printf("%d\n",( ret * modInverse(2,mod) ) %mod );
    }
}
