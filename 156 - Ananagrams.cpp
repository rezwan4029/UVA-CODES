/*
    Rezwan_4029
    AUST , CSE-25
*/
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#define pb push_back
#define EPS 1e-10
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

string fnc(string s){
    rep(i,s.size()){
        s[i] = tolower(s[i]);
    }
    sort(s.begin(),s.end());
    return s ;
}

int main(){
    set<string>G,ans;
    string s ;
    while(cin >> s && s != "#" ){
        if(s.size()) {
            if(G.find(s) ==  G.end() ) G.insert(s);
        }
    }
    ans = G ;
    map<string,int>Cnt;
    map<string,string>hash;
    forstl(it,G){
           string z = fnc(*it);
           Cnt[z]++;
           if(Cnt[z] > 1 ){
                ans.erase(*it);
                ans.erase(hash[z]);
           }
           hash[z] = *it ;
    }
    forstl(it,ans)cout << *it << endl;
}
