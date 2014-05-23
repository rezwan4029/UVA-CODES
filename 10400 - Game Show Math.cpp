#include <bits/stdc++.h>
using namespace std ;
const int offset  = 32000 ;
const int MX = offset*2 + 7 ;
bool dp[111][MX];
bool Vis[111][MX];
int  Dir[111][MX];
int N , K , A[111] ;
enum{ ADD = 1 , SUB , DIV , MUL };
bool solve(int pos , int s ){
    if( pos == N ) return ( s == K );
    bool &ret = dp[pos][s+offset];
    if( Vis[pos][s+offset] ) return ret ;
    Vis[pos][s+offset] = true ;
    ret = false;

    if( A[pos] != 0 and s % A[pos] == 0 and !ret ){
        Dir[pos][s+offset] = DIV ;
        ret |= solve(pos+1,s/A[pos]);
    }
    if( s * A[pos] <= offset and s * A[pos] >= -offset and !ret ){
        Dir[pos][s+offset] = MUL ;
        ret |= solve(pos+1,s*A[pos]);
    }
    if( s + A[pos] <= offset and !ret ){
        Dir[pos][s+offset] = ADD ;
        ret |= solve(pos+1,s+A[pos]);
    }
    if( s - A[pos] >= -offset and !ret ){
        Dir[pos][s+offset] = SUB ;
        ret |= solve(pos+1,s-A[pos]);
    }
    return ret ;
}
void go(int pos , int s ){
    if( pos == N ) return ;
    if( Dir[pos][s+offset] == MUL ){
        printf("*%d",A[pos]);
        go(pos+1,s*A[pos]);
    }
    else if( Dir[pos][s+offset] == DIV ){
        printf("/%d",A[pos]);
        go(pos+1,s/A[pos]);
    }
    else if( Dir[pos][s+offset] == ADD ){
        printf("+%d",A[pos]);
        go(pos+1,s+A[pos]);
    }
    else if( Dir[pos][s+offset] == SUB ){
        printf("-%d",A[pos]);
        go(pos+1,s-A[pos]);
    }
}
int main(){
    int T ;
    scanf("%d",&T);
    for( int cs = 1 ; cs <= T ; cs++ ){
        memset(Vis,false,sizeof Vis);
        memset(Dir,false,sizeof Dir);
        scanf("%d",&N);
        for( int i = 0 ; i < N ; i++ ) scanf("%d",A+i);
        scanf("%d",&K);
        bool Ans = solve(1,A[0]);
        if(Ans == false ) puts("NO EXPRESSION");
        else {
           // puts("ok..");
            printf("%d",A[0]);
            go(1,A[0]);
            printf("=%d\n",K);
            //puts("");
        }
        //cout << (5*7)/4 << endl;
    }
}
