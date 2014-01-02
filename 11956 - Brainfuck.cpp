/*
    Rezwan_4029 , AUST
*/
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <sstream>
#include <set>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
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
typedef map<string,int>msi;
typedef map<int,int>mii;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 1e6 + 7 ;
char fuck[MX];
int Ans[107];

int main(){
    FI;
    int test = II ;
    For(cs,test){
        int p = 0 ;
        scanf("%s",fuck);
        int len = strlen(fuck);
        ms(Ans,0);
        rep(i,len){
            char x = fuck[i] ;
            if( x == '>' ){
                p++;
                if(p == 100 ) p = 0 ;
            }else if( x == '<' ){
                p--;
                if(p == -1 ) p = 99 ;
            }else if( x == '+' ){
                Ans[p]++;
                if(Ans[p] == 256 ) Ans[p] = 0 ;
            }else if( x == '-' ){
                Ans[p]--;
                if(Ans[p] == -1 ) Ans[p] = 255 ;
            }
        }
        printf("Case %d:",cs);
        rep(i,100) printf(" %02X",Ans[i]);
        puts("");
    }
}
