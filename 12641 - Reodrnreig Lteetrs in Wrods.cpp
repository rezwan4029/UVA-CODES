/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

map<string,string>Map;

string a , b ;

string fnc(string s){
    int l = s.size() ;
    string x = "" , r = "" ;
    For(i,l-2) x += s[i] ;
    sort(all(x));
    r += s[0] ;
    r += x ;
    r += s[l-1];
    return r ;
}

int main(){
    int t = II ;
    getchar();
    while(t--){
        Map.clear();
        getline(cin,a);
        getline(cin,b);
        vector<string>St = Split(a);
        forstl(it,St){
            string now = fnc( *it ) ;
            if(Map.find(now) == Map.end()) Map[now] = *it ;
        }
        St.clear();
        St = Split(b);
        vector<string>ans ;
        forstl(it,St){
            string now = fnc( *it ) ;
            if(Map.find(now) != Map.end() ) ans.pb( Map[now] );
            else ans.pb(*it);
        }
        int N = ans.size() ;
        rep(i,N){
            if(i)printf(" ");
            cout << ans [i] ;
        }
        cout << endl;
    }
}
