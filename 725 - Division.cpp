/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 307 ;
const int INF = 1e8 + 7;

bool check(int n ){
    bool use[ 12 ] ;
    ms(use,0);
    while( n ){
        int x = n % 10 ;
        if( use[x]  )return false ;
        use[x] = true ;
        n /= 10 ;
    }
    return true ;
}

string toString(int x){
     stringstream ss ;
     ss << x;
     return ss.str();
}

bool ok(string x , string y ){
    int cnt[12];
    ms(cnt,0);
    if( y.size() == 4 ) cnt[0]++;
    for( int i = 0 ; x[i] ; i++ ) cnt[ x[i]-'0' ]++;
    for( int i = 0 ; y[i] ; i++ ) cnt[ y[i]-'0' ]++;
    rep(i,10) if(cnt[i] > 1 ) return false ;
    return true ;
}

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
       freopen ("out.txt","w",stdout);
    #endif
   // forab(i,2,79) cout << i << endl;
    //return 0 ;
    vi grp;
    vector<string>YY;
    for( int i = 1000 ; i < 100000 ; i++ ){
        if( check(i) ) {
            grp.pb(i);
            YY.pb( toString(i) ) ;
        }
    }
    sort( all(grp) );
    int tot = grp.size() ;
    int n ;
    bool p = false ;
    while( scanf("%d",&n) && n ){
        if( p ) puts(""); p = 1 ;
        vector< pair<string,string> >Ans;
        for( int i = 0 ; i < tot ; i++  ){
            int now = grp[i] * n ;
            string x = toString(now);
            string y = YY[i];
            if(x.size() == 4 )continue;
            if( x.length() > 5 ) break ;
            if(ok(x,y)) {
                if( y.size() == 4 ) y = "0" + y ;
                Ans.pb( make_pair(x,y) );
            }
        }
        int sz = Ans.size() ;
        if( sz == 0 ) printf("There are no solutions for %d.\n",n);
        else {
            sort( all(Ans) );
            rep(i,sz) printf("%s / %s = %d\n",Ans[i].first.c_str() , Ans[i].second.c_str(),n);
        }
    }
}
