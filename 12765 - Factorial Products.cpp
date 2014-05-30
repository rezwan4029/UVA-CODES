#include <bits/stdc++.h>
using namespace std;

const int MX = 2007 ;
vector<int> pr ;
int BT[MX/64];
void sieve() {
    memset( BT , -1, sizeof BT );
    #define gP(n) ( BT[n>>6] &  (1<<((n>>1)&31) ) )
    #define rP(n) ( BT[n>>6] &=~(1<<((n>>1)&31) ) )
    int SQ = sqrt (MX) + 1;
    for(int i = 3 ; i < SQ; i += 2 ) if( gP( i ) )
            for( int j = i * i , k = i * 2 ; j < MX; j += k ) rP( j );
    pr.push_back(2);
    for(int i = 3; i < MX; i += 2 )
        if( gP( i ) ) pr.push_back(i) ;
}

int Factors[MX][MX];
void preGen(){
    memset(Factors,0,sizeof Factors);
    for( int n = 2 ; n <= 1000 ; n++ ){
        for( int i = 0 ; pr[i] <= n ; i++ ){
            for( int j = pr[i] ; j <= n ; j *= pr[i] ){
                Factors[n][ pr[i] ] += n/j ;
            }
        }
    }
}
int Ans1[MX] , Ans2[MX];
bool Find(){
    for( int i = 0 ; i < 800 ; i++ ){
        if( Ans1[i] != Ans2[i] ) return false ;
    }
    return true ;
}
int main(){
    sieve();
    preGen();
    int n , m ;
    while( scanf("%d %d",&n,&m) ){
        if( n == 0 and m == 0 ) return 0 ;
        memset(Ans1,0,sizeof Ans1);
        memset(Ans2,0,sizeof Ans2);
        for( int i = 0 ; i < n ; i++ ){
            int x ;
            scanf("%d",&x);
            for( int j = 0 ; j < 800 ; j++ ) Ans1[j] += Factors[x][j];
        }
        for( int i = 0 ; i < m ; i++ ){
            int x ;
            scanf("%d",&x);
            for( int j = 0 ; j < 800 ; j++ ) Ans2[j] += Factors[x][j];
        }
        if( Find() ) puts("YES");
        else puts("NO");
    }
}
