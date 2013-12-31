/*
    Rezwan_4029 , AUST
*/
#include <bits/stdc++.h>
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


#define MAXN 10507 // total size of patterns here 150 patterns  and max length of pattern is 70 . so 150 * 70 = 10500
#define CHARSET  26 // lower(26)

int Value(char x){
    return x - 'a' ;
}
struct AhoCorasick{
    vector<int> mark[MAXN];
    int end , failure[MAXN];
    int Trie[MAXN][CHARSET];
    void __init(){
        mark[0].clear();
        fill(Trie[0], Trie[0] + CHARSET, -1);
        end = 1;
    }
    void add(char *s, int t){
        int pos = 0 ;
        for(int i = 0 ; s[i] ; i++ ){
            int ch = Value(s[i]);
            if (Trie[pos][ch] == -1){
                mark[end].clear();
                fill(Trie[end], Trie[end] + CHARSET, -1);
                Trie[pos][ch] = end++;
            }
            pos = Trie[pos][ch];
        }
        mark[pos].pb(t);
    }
    void computeFailure()
    {
        queue<int> Q ;
        failure[0] = 0;
        rep(i,CHARSET){
            if (Trie[0][i] != -1){
                failure[ Trie[0][i] ] = 0;
                Q.push( Trie[0][i] );
            }
            else Trie[0][i] = 0;
        }
        while (!Q.empty()){
            int p = Q.front(); Q.pop();
            forstl(it , mark[ failure[p] ] ) mark[p].pb( *it );
            rep(i,CHARSET){
                if (Trie[p][i] != -1){
                    failure[ Trie[p][i] ] = Trie[ failure[p] ][i];
                    Q.push( Trie[p][i] );
                }
                else
                    Trie[p][i] = Trie[ failure[p] ][i];
            }
        }
    }
}solve;

char P[157][87]; // 100 patterns and max Length of pattern is 80
int Counts[157]; // Count which pattern occurs how many times

void CountFreq(char *T){
    for(int i = 0 , pos = 0 ; T[i] ; i++ ) {
            int ch = Value(T[i]);
            pos = solve.Trie[ pos ][ ch ];
            if (pos == 0) continue;
            forstl(it , solve.mark[ pos ] )  Counts[ *it ]++;
    }
}

char T[1000007]; // Maximum size of Text

int main(){
    //freopen("in.txt", "r", stdin);
    int noOfpatterns ;
    while( scanf("%d",&noOfpatterns) && noOfpatterns ){
        rep(i,noOfpatterns) scanf("%s",P[i]);
        solve.__init();
        rep(i,noOfpatterns) solve.add(P[i],i);
        solve.computeFailure();
        memset(Counts,0,sizeof Counts);
        scanf("%s",T);
        CountFreq(T);
        int Ans = 0 ;
        rep(i,noOfpatterns) Ans = max(Ans,Counts[i]);
        printf("%d\n",Ans);
        rep(i,noOfpatterns) if( Ans == Counts[i] ) printf("%s\n",P[i]);
    }
}

