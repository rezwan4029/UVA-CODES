/*
    rezwan4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})
#define gc getchar
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

vs Split( string s ) {
    vs a ;
    istringstream ss(s) ;
    string b ;
    while(ss >> b ) a.pb( b ) ;
    return a;
}
int Priority(string x){
    if( x == "(" ) return 0 ;
    if( x == "+" or x == "-" ) return 1 ;
    if( x == "*" or x == "/" ) return 2 ;
    return -1;
}
bool isOperator(string x ){
    return x == "+" or x == "-" or x == "*" or x == "/" ;
}
vs InfixToPostfix(vs S){
    int Len = S.size();
    stack<string>Stk;
    vs Ans ;
    rep(i,Len){
        if( S[i] == "(" ) Stk.push("(");
        else if( S[i] == ")" ){
            while( !Stk.empty() and Stk.top() != "(" ){
                Ans.pb( Stk.top() );
                Stk.pop();
            }
            Stk.pop();
        }
        else if( isOperator(S[i]) ){
            while( !Stk.empty() and Priority( Stk.top() ) >= Priority(S[i]) ){
                Ans.pb( Stk.top() );
                Stk.pop();
            }
            Stk.push( S[i] );
        }
        else Ans.pb( S[i] );
    }
    while( !Stk.empty() ){
        Ans.pb( Stk.top() );
        Stk.pop();
    }
    return Ans;
}
double toDouble(string s) {
    double r = 0 ;
    istringstream sin(s);
    sin >> r ;
    return r ;
}
double get( double a , double b , string op ){
    if( op == "+" ) return a + b ;
    if( op == "-" ) return a - b ;
    if( op == "*" ) return a * b ;
    if( op == "/" ) return a / b ;
}
double CalcPostfix(vs postfix){
    stack<double>Stk;
    forstl(i,postfix){
        if( isOperator(*i) ){
            double a = Stk.top() ; Stk.pop();
            double b = Stk.top() ; Stk.pop();
            Stk.push( get(b,a,*i) );
        }else Stk.push( toDouble(*i) );
    }
    return Stk.top();
}
int main() {
   // freopen("input.txt","r",stdin);
    int T = II ;
    For(cs,T){
        string Str ;
        getline(cin,Str);
        vs Tokens = Split(Str);
       // forstl(i,Tokens) cout << *i << " " ;
       // puts("");
        Tokens = InfixToPostfix(Tokens);
      //  forstl(i,Tokens) cout << *i << " " ;
       // puts("");
        double Ans = CalcPostfix(Tokens) ;
        printf("%.2lf\n",Ans);
    }
}
/*
3.00 4.50 +
5.00 2.50 3.00 * -
7.00 3.00 / 4.00 3.00 7.00 * - +
*/
