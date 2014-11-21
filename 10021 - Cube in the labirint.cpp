/*
   rezwan_4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair

#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

typedef vector<int>    vi;
typedef vector<Long>   vl;
typedef vector<string> vs;
typedef vector<pii>  vpii;
typedef set<int> si;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define __( args... ) { dbg , args ; cerr << endl; }

struct debugger {
    template< typename T > debugger & operator , ( const T &v ) {
        cerr << v << "\t" ;
        return *this;
    }
}dbg;
// Pair Print
template< class A , class B > ostream &operator << ( ostream &o, const pair<A,B> &p ) {
    return o<<"(" << p.ff << ", " << p.ss << ")" ;
}
//Vector Print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
//Set Print
template<class T> ostream& operator<<(ostream& o, const set<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
template<class T> inline void MAX( T &a , T b) { if (a < b ) a = b; }
template<class T> inline void MIN( T &a , T b) { if (a > b ) a = b; }

//Fast Reader
template< class T > inline bool read( T &x ) {
    int c = getchar() ;
    int sgn = 1;
    while( ~c && c < '0' || c > '9' ) {
        if( c == '-' )sgn = -1 ;
        c = getchar() ;
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = getchar() ) x = x * 10 + c - '0' ;
    x *= sgn ;
    return ~c ;
}


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool invalid_moves[15][15][15][15] , Vis[15][15][10];
int r , c ;

bool isValid(int x , int y){
    if( x >= 1 && y >= 1 && x <= r && y <= c ) return true ;
    return false;
}
struct Node{
    int x , y , cost ,dir;
    Node(){}
    Node(int _x , int _y , int _c ,int _d ){
        x = _x , y = _y , cost = _c , dir = _d;
    }
};
Node source , sink ;
enum {Up=0,Down,Right,Left};
enum {U=0,D,L,R,F,B};
int rot(int dir,int i){
    if(dir == U) {
        if(i == Up) dir = B;
        else if(i == Down) dir = F;
        else if(i == Right) dir = R;
        else dir = L;
    }
    else if(dir == D){
        if(i == Up) dir = F;
        else if(i == Down) dir = B;
        else if(i == Right) dir = L;
        else dir = R;
    }
    else if(dir == L){
        if(i == Up){ }
        else if(i == Down){ }
        else if(i == Right)dir = U;
        else dir = D;
    }
    else if(dir == R){
        if(i == Up){ }
        else if(i == Down){ }
        else if(i == Right) dir = D;
        else dir = U;
    }
    else if(dir == F){
        if(i == Up) dir = U;
        else if(i == Down) dir = D;
        else if(i == Right){ }
        else{ }
    }
    else if(dir == B){
        if(i == Up) dir = D;
        else if(i == Down) dir = U;
        else if(i == Right){ }
        else{ }
    }
    return dir;
}
int bfs(){
    memset(Vis,false,sizeof Vis);
    queue<Node>Q;
    Q.push( source );
    while( !Q.empty() ){
        Node u = Q.front();
        Q.pop();
        if( u.x == sink.x && u.y == sink.y && u.dir == 0) return u.cost ;
        if(Vis[u.x][u.y][u.dir]) continue;
        Vis[u.x][u.y][u.dir] = true;
        for( int i = 0 ; i < 4 ; i++ ){
            int nx = dx[i] + u.x;
            int ny = dy[i] + u.y;
            if( isValid(nx,ny) && !invalid_moves[u.x][u.y][nx][ny]){
                Q.push( Node(nx,ny,u.cost + 1,rot(u.dir,i)) );
            }
        }
    }
    return -1;
}
vector<int>Split(string s ){
    vector<int>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) {
        int r = 0 ;
        istringstream sin(token);
        sin>>r;
        ret.push_back( r ) ;
    }
    return ret;
}
void Input(){
   // getchar();
    string s ;
    bool Vertical = true ;
    while(true){
        getline(cin,s);
        if( s.size() == 0 ) break ;
        if( s[0] == 'v' ) {
            Vertical = true ;
            continue ;
        }
        if( s[0] == 'h' ) {
            Vertical = false ;
            continue ;
        }
        vector<int>get = Split(s);
        int n = get[0];
        int m = get[1];
        if( Vertical ) invalid_moves[n+1][m][n][m] = invalid_moves[n][m][n+1][m] = true ;
        else invalid_moves[n][m+1][n][m] = invalid_moves[n][m][n][m+1] = true ;
        //cout << n << "  " << m << endl ;
    }
}
int main(){
#ifdef LOCAL
    freopen("bin.txt","r",stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int T = II ;
    while(T--){
        r = II , c = II ;
        memset(invalid_moves,false,sizeof invalid_moves);
        int x = II , y = II ;
        source = Node(x,y,0,0);
        x = II , y = II ;
        sink = Node(x,y,0,0);
        Input();
        int ans = bfs();
        if( ans == -1 ) puts("No solution");
        else printf("%d\n",ans);
        if(T)puts("");
    }
}
