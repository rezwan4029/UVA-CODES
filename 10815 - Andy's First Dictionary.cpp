#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++ )
#define forstl(i,n) for(__typeof(n.begin()) i = n.begin() ; i != n.end() ; i++)
typedef long long ll;

int main(){
    string s ;
    set<string>SS;
    while(getline(cin,s)){
        rep(i,s.size()) s[i] = tolower(s[i]);
        s[s.size()] = '*';

        string z = "";
        bool f = false ;
        rep(i,s.size()+1){
            if(islower(s[i])){
                z += s[i];
                f = true ;
            }else if(f){
                SS.insert(z);
                z = "";
                f = false ;
            }
        }
    }
        forstl(it,SS) cout << *it << endl;
}
