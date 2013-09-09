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

ll ret(string s ){
    ll r = 0 ;
    int p = 0 ;
    reverse(all(s));
    rep(i,s.size()){
        r = r + pow(2,p)*(s[i]-'0');
        p++;
    }
    return r ;
}
int main(){
    freopen("in.txt", "r", stdin);
    int T = II ;
    For(cs,T){
        string s1 , s2 ;
        cin >> s1 >> s2 ;
        ll a = ret(s1) , b = ret(s2);
        if(__gcd(a,b)!=1) printf("Pair #%d: All you need is love!\n",cs);
        else printf("Pair #%d: Love is not all you need!\n",cs);
    }
}
