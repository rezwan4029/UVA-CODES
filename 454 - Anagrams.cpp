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
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef long long ll;
#define all(X) X.begin() , X.end()
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

string get(string s){
    sort(all(s));
    string z ;
    forstl(it,s){
        if(isspace(*it))continue;
        z += *it;
    }
    return z ;
}
int main(){
    //freopen("in.txt", "r", stdin);
    int t = II ; getchar(); getchar();
    while(t--){
        map<string,string>Hash;
        vector<string>S;
        char s[20008];
        while(gets(s)){
            if(strlen(s)==0)break;
            S.pb(s);
            Hash[s] = get(s);
        }
        sort(all(S));
        int sz = S.size();
        rep(i,sz)
            forab(j,i+1,sz-1)
                if( Hash[ S[i] ] == Hash[ S[j] ] )
                        cout << S[i] << " = " << S[j] << endl;
        if(t)puts("");
    }

}
