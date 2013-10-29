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
#define EPS 1e-7
#define pi acos(0.0)
using namespace std;

typedef long long ll;
typedef vector<int> vi ;
typedef vector<ll>vl;

#define forab(i, a, b)	for (__typeof (b) i = (a), i##_b = (b); i <= i##_b; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b) i = (b), i##_a = (a); i >= i##_a; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 1002 ;
int Cnt , k ;
string grp[MX];
int dp[MX][30];
int gC[MX][30];

int fn(int x)
{
    int cnt = 0 ;
    rep(i,26) cnt += ( gC[x][i]  > 0  );
    return cnt ;
}

int solve(int g , int prevChar ){
    if( g == Cnt )return 0 ;
    int &ret = dp[g][prevChar];
    if( ret != -1 )return ret ;
    ret = MX ;
    int gp = fn(g);
    rep(i,26) {
            if(gC[g][i] == 0 ) continue ;
            int add = gp ;
            if(prevChar == i ) add--;
            rep(j,26){
                    if(gC[g][j] == 0 ) continue ;
                    ret = min( ret , solve(g+1,j) + add + ( j == i && gp > 1 ? 1 : 0 )  );
            }
    }
    return ret ;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int test = II ;
    For(cs,test)
    {
        scanf("%d",&k);
        string Str ;
        cin >> Str ;
        int len = Str.size();
        Cnt = 0 ;
        ms(gC,0);
        for(int i = 0 ; i < len ; i += k )
        {
            string x = "" ;
            for(int j = i , c = 0 ; c < k && j < len ; c++ , j++ )x += Str[j];
            grp[Cnt] = x ;
            int l = x.size() ;
            rep(p,l) gC[ Cnt ][ x[p] - 'a' ]++;
            Cnt++;
        }
        ms(dp,-1);
        int ans = solve(0,26) ;
        printf("%d\n",ans);
    }
}
