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

const int MX = 107 ;
int mat[MX][MX];
int clr[MX][MX];
int n , m ;
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < m && y < n ;
}
int p , q , cx, cy ;
vector<pii>pos;
int main(){
    //freopen("in.txt","r",stdin);
    int t = II ;
    For(cs,t){
        pos.clear();
        m = II , n = II ;
        rep(i,m)rep(j,n) { mat[i][j] = II ; if( mat[i][j]  ) pos.pb( pii(i,j) ); }
        p = II , q = II ;
        rep(i,p)rep(j,q)  clr[i][j] = II ;
        cx = p / 2 ;
        cy = q / 2 ;
        forstl(it,pos){
            rep(i,p)rep(j,q){
                int X = i - cx,Y = j - cy;
                if(valid(it->first + X , it->second + Y) ){
                    mat[ it->first + X ][ it->second + Y] |= clr[i][j];
                }
            }
        }
        printf("Case %d:\n",cs);
        rep(i,m){
            rep(j,n){
                if(j) printf(" ");
                printf("%d",mat[i][j]);
            }
            puts("");
        }
    }
}
