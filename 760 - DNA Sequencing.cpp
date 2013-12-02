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

const int MX = 307 ;

string s1 , s2 ;

int dp[MX][MX];
int n1 , n2 ;
int solve(int i , int j ){
    if( i >= n1 || j >= n2 ) return 0 ;
    int &ret = dp[i][j];
    if( ret != -1 ) return ret ;
    ret = 0 ;
    if(s1[i] == s2[j])ret = solve(i+1,j+1) + 1 ;
    return ret ;
}
int main(){
    bool p = false ;
    while( cin >> s1 >> s2 ) {
            if( p ) puts("") ; p = true ;
            n1 = s1.size() ;
            n2 = s2.size() ;
            memset(dp,-1,sizeof dp);
            int mxMatch = 0 ;
            rep(i,n1)rep(j,n2) mxMatch = max( mxMatch , solve(i,j) );
           // cout << mxMatch << endl;
            if( mxMatch == 0 ) { puts("No common sequence."); continue ; }
            set<string>Ans;
            rep(i,n1)rep(j,n2)
                if( dp[i][j] == mxMatch ){
                        string ret ;
                        forab(k,i,i+mxMatch-1)ret += s1[k];
                        Ans.insert(ret);
                }
            forstl(i,Ans) cout << *i << endl;
    }
}
