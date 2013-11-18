/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
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

int priority(char op){
    if( op == '+' || op == '-' ) return 1 ;
    if( op == '*' || op == '/' ) return 2 ;
    return -1 ;
}

bool isOperator(char op){
    return ( op == '+' || op == '-' || op == '*' || op == '/' ) ;
}

string  Infix2Post( string Exp){
    int len = Exp.size() ;
    stack<char>Stk;
    string ret ;
    rep(i,len) {
        if(Exp[i] == '(' ) Stk.push(Exp[i]);
        if(Exp[i] == ')' ){
            while(Stk.top() != '('){
                ret += Stk.top();
                Stk.pop();
            }
            Stk.pop();
        }
        if(isOperator(Exp[i])){
            if(Stk.empty() || Stk.top() == '(') Stk.push(Exp[i]);
            else {
                while( !Stk.empty() && priority( Exp[i] ) <= priority( Stk.top() ) ) {
                    ret += Stk.top();
                    Stk.pop();
                }
                Stk.push(Exp[i]);
            }
        }
        if( isdigit(Exp[i]) ) ret += Exp[i];
    }

    while(!Stk.empty()){
        if( Stk.top() != '(' ) ret += Stk.top();
        Stk.pop();
    }
    return ret;
}

char str[500000];

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int t = II ; getchar();
    gets(str);
    rep(cs,t) {
        if(cs) puts("");
        string Inp ;

        while( gets(str) ){
            if(!strcmp(str,""))break;
            Inp += str;
        }
        if(Inp == "")continue;
        string Ans = Infix2Post(Inp);
        printf("%s\n",Ans.c_str());
    }
}
