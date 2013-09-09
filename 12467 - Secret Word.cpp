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
#include<limits.h>
#include<map>
#include<sstream>
#include<time.h>
#include<set>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
using namespace std;
typedef long long ll;
#define all(X) X.begin() , X.end()
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

#define MAX_N 1000005

char str [MAX_N], pat [MAX_N];
int N, M, pi [MAX_N];
vector <int> occurance;

int failureFunction () {
    ms(pi,0);
    int i, shift = 0;
    for (i = 2; pat [i - 1]; ++i) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
        if (pat [shift] == pat [i - 1]) ++shift;
        pi [i] = shift;
    }
    return i - 1;
}

int KMP () {
    int i, shift = 0;
    occurance.clear ();
    M = failureFunction ();
    int ret = 0 ;
    for (i = 0; str [i]; ++i) {
        ret = max(ret,shift);
        while (shift > 0 && pat [shift] != str [i] ) shift = pi [shift];
        if (pat [shift] == str [i]) ++shift;
        if (shift == M) {
            return shift;
            occurance.push_back (i - M + 1);
            shift = pi [shift];
        }
        ret = max(ret,shift);
    }
    return ret;
}

int main(){
    int tst = II ;
    For(cs,tst){
        scanf("%s",&pat);
        memcpy(str,pat,sizeof pat);
        reverse(str,str+strlen(str));
        int pos = KMP();
        forba(i,pos-1,0)printf("%c",pat[i]);
        cout << endl;
    }
}
