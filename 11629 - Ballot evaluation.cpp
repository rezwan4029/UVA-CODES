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

const int MX = 100 + 7 ;
const int INF = 1e8 + 7;

vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

int toInt(string s){
    int r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

map<string,int>Hash;
string Str;

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
        int n , m ;
        scanf("%d %d",&n,&m) ;
        Hash.clear();
        rep(i,n){
            cin >> Str ;
            int x , y ;
            scanf("%d.%d",&x,&y);
            Hash[ Str ] = x*10 + y  ;
        }
        getchar();
        For(cs,m){
            getline(cin,Str);
            vector<string>get = Split(Str);
            int len = get.size() ;
            //rep(i,len) cout << get[i] << "  " ; puts("\n\n");
            double x = toInt( get[ len - 1  ] ) * 10  ;
            string rel = get[ len - 2 ];
            int ret = 0 ;
            rep(i,len-2){
                if( get[i] == "+" ) continue ;
                ret += Hash[ get[i] ];
            }
            if( rel == ">" ){
                 printf("Guess #%d was %s.\n" , cs ,  ret > x ? "correct" : "incorrect" );
            }
            else if( rel == "<" ){
                 printf("Guess #%d was %s.\n" , cs ,  ret < x ? "correct" : "incorrect" );
            }
            else if( rel == "<=" ){
                 printf("Guess #%d was %s.\n" , cs ,  ret <= x ? "correct" : "incorrect" );
            }
            else if( rel == ">=" ){
                 printf("Guess #%d was %s.\n" , cs ,  ret >= x ? "correct" : "incorrect" );
            }
            else if( rel == "=" ){
                 printf("Guess #%d was %s.\n" , cs ,  ret == x ? "correct" : "incorrect" );
            }
        }
}
