/*
    Rezwan_4029 , AUST
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print
template<class T> inline void MAX(T &a , T b){ if (a < b ) a = b;}
template<class T> inline void MIN(T &a , T b){ if (a > b ) a = b;}

//Fast Reader
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int MX = 100007;
const int INF = 1e9 ;
int tx[MX * 4];
int ty[MX * 4];
bool divX[MX * 4];
pii points[MX];

bool cmpX(pii a, pii b) {
    return a.first < b.first;
}
bool cmpY(pii a, pii b) {
    return a.second < b.second;
}

void buildTree(int node, int left, int right) {
    if (left > right)
        return;
    int mid = (left + right) >> 1;

    //sort(points + left, points + right + 1, divX ? cmpX : cmpY);
    int minx = +INF;
    int maxx = -INF;
    int miny = +INF;
    int maxy = -INF;
    for (int i = left; i <= right; i++) {
        minx = min(minx, points[i].first);
        maxx = max(maxx, points[i].first);
        miny = min(miny, points[i].second);
        maxy = max(maxy, points[i].second);
    }
    divX[node] = (maxx - minx) >= (maxy - miny);
    nth_element(points + left, points + mid, points + right + 1, divX[node] ? cmpX : cmpY);

    tx[node] = points[mid].first;
    ty[node] = points[mid].second;
    if (left == right) return;
    buildTree(node * 2, left, mid - 1);
    buildTree(node * 2 + 1, mid + 1, right);
}

Long closestDist;
int closestNode;

void findNearestNeighbour(int node, int left, int right, int x, int y) {
    if (left > right)
        return;
    Long dx = x - tx[node];
    Long dy = y - ty[node];
    Long d = dx * dx + dy * dy;
    if (closestDist > d && d > 0 ) {
        closestDist = d;
        closestNode = node;
    }
    if (left == right) return;

    Long delta = divX[node] ? dx : dy;
    Long delta2 = delta *  delta;
    int mid = (left + right) >> 1;
    int n1 = node << 1;
    int l1 = left;
    int r1 = mid - 1;
    int n2 = node << 1 | 1;
    int l2 = mid + 1;
    int r2 = right;
    if (delta > 0) swap(l1, l2), swap(r1, r2), swap(n1, n2);

    findNearestNeighbour(n1, l1, r1, x, y);

    if (delta2 < closestDist) findNearestNeighbour(n2, l2, r2, x, y);
}

int findNearestNeighbour(int n, int x, int y) {
    closestDist = LLONG_MAX;
    findNearestNeighbour(1, 0, n - 1, x, y);
    return closestNode;
}
pii inp[MX];
int main() {
    FI;
    int test ;
    read(test);
    For(cs,test){
        vpii p ;
        int N ;
        read(N);
        rep(i,N) {
            int x , y ;
            read(x) , read(y);
            p.pb( mp(x,y) );
            inp[i] = p[i];
        }
        p.resize( unique( all(p) ) - p.begin());
        int n = p.size();
        rep(i,n) points[i] = p[i];
        ms(divX,false);
        buildTree(1, 0, n - 1) ;
        rep(i,N) {
            findNearestNeighbour(n, inp[i].ff , inp[i].ss );
            printf("%lld\n",closestDist);
        }
    }
    return 0;
}
