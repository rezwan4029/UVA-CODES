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

const int MX = 107 ;
const int INF = 1e8 + 7;

vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

Long toInt(string s){
    Long r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

si ST[MX];


int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    int test = II ;
    bool p = false ;
    For(cs,test){
        if( p ) puts("") ; p = true ;
        string str ;
        int people = II , tree = II ;
        getchar();
        while( getline(cin,str) ){
            if( str.size() == 0 ) break ;
            vector<string> r = Split(str);
            int x = toInt(r[0]);
            int y = toInt(r[1]);
            ST[x].insert(y);
        }
        int Ans = people;
        sort(ST+1,ST+people+1);
        For(i,people) {
            int j ;
            for( j = i + 1 ; j <= people ; j++ ) if( ST[i] != ST[j] ) break ;
            Ans -= ( j - i - 1 ) ;
            i = j - 1 ;
        }
        printf("%d\n",Ans);
        For(i,people) ST[i].clear();
    }
}
