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


int SZ(string s) {
    return s.size();
}

bool startsWith(string a , string b ){ // Is a starts with b ?
    int len = SZ(b);
    rep(i,len)if(a[i]!=b[i]) return false;
    return true;
}

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int test ; scanf("%d",&test);
    For(cs,test) {
        int k = II , w = II ;
        string Str , Ans = "" , Pre = "000000000000000";
        rep(it,w)
        {
             cin >> Str ;
             if( Str == Pre )continue ;
             Pre = Str ;
             if( SZ(Ans) == 0 ) { Ans += Str  ;  continue; }
             int pos = SZ(Ans) - k ;
             string Temp = ""; int nPos = 0 ;
             for( int x = pos ; x < SZ(Ans) ; x++ ){
                    Temp = Ans.substr(x);
                    if( startsWith(Str,Temp) )  break;
                    nPos++;
             }
             for( int i =  k - nPos ; i < k ; i++ ) Ans += Str[i];
        }
        printf("%d\n",Ans.size());
    }
}
