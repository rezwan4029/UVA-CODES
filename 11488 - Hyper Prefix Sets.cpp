/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 50000 * 2 + 7  ;
const int INF = 1e8 + 7;

struct Node{
    Long end;
    Node *next[ 3 ];
    Node(){
        end = 0 ;
        ms(next,NULL);
    }
}*root;

Long Ans ;
void insert(char *s){
    Node *curr = root;
    for( int i = 0 ; s[i] ; i++ ){
        if( curr->next[ s[i] - '0' ] == NULL  ){
            curr->next[ s[i] - '0' ] = new Node();
        }
        curr = curr->next[ s[i] - '0' ] ;
        ++curr->end;
        Ans = max( Ans , curr->end *(i+1) );
    }

}

void remove(Node *curr){
    rep(i,3) if( curr->next[i] ) remove( curr->next[i] );
    delete(curr);
}

char str[MX];
int main(){
    #ifdef LOCAL
     // freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    int test = II ;
    For(cs,test){
        root = new Node();
        int N = II ;
        Ans = 0 ;
        rep(i,N) {
            scanf("%s",&str);
            insert(str);
        }
        printf("%lld\n",Ans);
        remove(root);
    }
}
