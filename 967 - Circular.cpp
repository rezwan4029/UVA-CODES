/*
    Rezwan_4029 , AUST
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define makeUnique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
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
typedef vector<pll> vpii;

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
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");printf("%2d",a[i][j]);}cout<<endl;}

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
const int MX = 1e6 + 7 ;
const unsigned MXN = 16667 , MAX_S = sqrt(MXN/60);
unsigned short composite[MXN];
vector<int> pr;
bool isPrime[MX];
void sieve() {
    unsigned w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
    unsigned mod[16][16], di[16][16], num;
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++){
            di[i][j] = (w[i] * w[j])/60;
            mod[i][j] = lower_bound(w, w + 16, (w[i]* w[j])%60) - w;
        }
    pr.push_back(2) , pr.push_back(3) , pr.push_back(5);
    isPrime[2] = isPrime[3] = isPrime[5] = true ;
    memset(composite, 0, sizeof composite);
    for(unsigned i = 0; i < MXN; i++)
        for(int j = (i==0); j < 16; j++) {
            if(composite[i] & (1<<j)) continue;
            pr.push_back( num = 60 * i + w[j] );
            isPrime[num] = true ;
            if(i > MAX_S) continue;
            for(unsigned k = i, done = false; !done; k++)
                for(int l = (k == 0); l < 16 && !done; l++)
                {
                    unsigned mult = k * num + i * w[l] + di[j][l];
                    if( mult >= MXN ) done = true;
                    else composite[mult] |= 1<<mod[j][l];
                }
        }
}
Long toInt(string s){
    Long r = 0 ;
    int len = s.size();
    rep(i,len) r = r * 10 + s[i] - '0';
    return r;
}
string toString(Long number){
    stringstream ss;
    ss << number;
    return ss.str();
}
bool isCircular(int x ){
    string num = toString(x);
    int len = num.size();
    rep(i,len){
        string cur = num.substr(i,len-i)  + num.substr(0,i) ;
        int val = toInt(cur);
        if( isPrime[val] == false ) return false ;
    }
    return true ;
}
int dp[MX];
int main(){
    //FI;
    sieve();
    forab(i,100,MX-7) {
        if( isPrime[i] )
            dp[i] += dp[i-1] + isCircular(i);
        else
            dp[i] = dp[i-1] ;
    }
    int a , b ;
    for( ;; ){
        read(a) ;
        if( a == -1 ) break ;
        read(b);
        int ans = dp[b] - dp[a-1];
        if( ans == 0 ) puts("No Circular Primes.");
        else if( ans == 1 ) puts("1 Circular Prime.");
        else printf("%d Circular Primes.\n",ans);
    }
}
