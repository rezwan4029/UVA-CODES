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

const int MX = 200 + 7 ;
const int INF = 1e8 + 7;

string Str ;
vector<string>dict;
int N ;
int d[MX];
vi edges[MX];

vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

bool Ok(string a, string b)
{
    int la = a.size() ;
    int lb = b.size() ;
    if( la != lb ) return false ;
    int c = 0 ;
    for( int i = 0 ; i < lb ; i++ ){
            if( a[i] != b[i] ) c++;
    }
    return  (c == 1 );
}

map<string,int>Map;

int bfs(string st , string en ){
    memset(d,-1,sizeof d);
    int src = Map[ st ];
    int dest = Map[ en ];
    queue<int>Q;
    Q.push(src);
    d[src] = 0 ;
    while( !Q.empty() ){
        int u = Q.front() ;
        Q.pop();
        forstl(it,edges[u]){
            int v = *it ;
            if( d[v] > d[u] +1 || d[v] == -1 ){
                d[v] = d[u] +1 ;
                Q.push(v);
            }
        }
    }
    return d[dest];
}
int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    bool p = false ;
    For(cs,test){
        if(p) puts(""); p = true ;
        N = 0 ;
        while( cin >> Str ){
            if( Str == "*" ) break ;
            dict.pb(Str);
            Map[ Str ] = ++N ;
        }
        rep(i,N) forab(j,i+1,N-1){
            if( Ok(dict[i],dict[j])){
                edges[ Map[ dict[i] ] ].pb( Map[ dict[j] ] );
                edges[ Map[ dict[j] ] ].pb( Map[ dict[i] ] );
            }
        }
        getchar();
        string s1 , s2 ;
        while( getline(cin,Str) ){
            if( Str.size() == 0 ) break ;
            vector<string>Ret = Split(Str);
            s1 = Ret[0] ;
            s2 = Ret[1] ;
            cout << s1 << " " << s2 << " " << bfs(s1,s2) << endl;
        }
        For(i,N) edges[i].clear();
        dict.clear() ;
        Map.clear() ;
    }
}
