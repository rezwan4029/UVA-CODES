/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
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

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


vector<string>Split(string s )
{
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

const int MX = 102;

vi Order;
int nV, nE ;
bool inValid[MX][MX] , Taken[MX];
map<string,bool>done;
map<int,char>Map;

void Reset(){
    Map.clear() , ms(inValid , false) , ms(Taken,false) , done.clear()  , Order.clear() ;
}

char Var[MX*MX] , Ins[MX*MX];

void __build() {
   vector<string> v = Split(Var);
    nV = 0 ;
    map<char,int>hash;
    forstl(it,v){
        string St = *it ;
        if( hash[ St[0] ] ) continue ;
        hash[ St[0] ] = ++nV ;
        Map[nV] = St[0];
    }
    v = Split(Ins);
    forstl(it,v){
         string St = *it ;
         char x = St[0] , y = St[2] ;
         inValid[ hash[y] ][ hash[x] ] = true ;
    }
}

bool check(int x) {
    for(int i = 0 ; i < Order.size() ; i++ ) {
        if( inValid[ Order[i]  ][ x ] ) return false ;
    }
    return true ;
}

string cat() {
    string St ;
    for( int i = 0 ; i < nV ; i++ ){
        St +=  Map[ Order[i] ] ;
    }
    return St ;
}

bool found ;

void BkTrk() {
    if(Order.size() == nV ){
        string St = cat();
        if( done[ St ] )  return ;
        done[ St ] = true ;
        for(int i = 0 ; i < nV ; i++ ){
            if( i ) printf(" ");
            printf("%c",Map[ Order[i] ] );
        }
        found = true ; puts("");
        return ;
    }
    for(int v = 1 ; v <= nV ; v++){
        if( Taken[v] == false ) {
            if( check(v) ) {
                Taken[v] = true ; Order.pb(v);
                BkTrk();
                Taken[v] = false ; Order.pop_back();
            }
        }
    }
}

int main() {
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int test ; scanf("%d",&test); getchar();
    for( int cs = 1 ; cs <= test ; cs++ ){
        getchar();
        gets(Var); gets(Ins);
        Reset(); __build();
        if(cs != 1 ) puts("");
        found = false ;
        BkTrk();
        if(!found)puts("NO");
    }
}
