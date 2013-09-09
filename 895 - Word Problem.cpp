/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<queue>
#define pb push_back
#define INF 1<<30
#define eps 1e-8
#define CS printf("Case #%d: ",cs++)
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
#define PI 3.1415926535897932384626433832795
using namespace std;
typedef  long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)


void print(map<char,int>m){
     forstl(it,m)cout << it->first << " " << it->second  << endl;
}
map<char,int>solve(string s){
    int len = s.length();
    map<char,int>temp;
    rep(i,len) if( !isspace(s[i]) )temp[ s[i] ]++ ;
    return temp;
}
bool check(map<char,int>X , map<char,int>Y ){
     for(char c = 'a' ; c <= 'z' ; c++ )if( X[c] > Y[c] ) return false ;
     return true;
}

int main(){
    map<int, map<char,int> >hash;
    string s ;
    int pos = 0 ;
    while( cin >> s && s != "#" ){
            hash[++pos] = solve(s);
          //  print(hash[s]);
    }
    getchar();
    while( getline(cin,s) && s != "#" ){
        map<char,int>temp = solve(s) ;
        //print(temp);
        int ans = 0 ;
        forstl(it,hash){
            ans += check( it->second , temp);
        }
        cout << ans << endl;
    }
}
