#include <bits/stdc++.h>
using namespace std ;
bool Vis[110][110] ;
int A[110][110];
map< int , pair<int,int> >Pos;
bool End ;
void Check() {
    for( int i = 0 ; i < 5 ; i++ ){
        int cnt = 0 ;
        for( int j = 0 ; j < 5 ; j++ ) {
            if( Vis[i][j] ) cnt++;
            else break ;
        }
        if( cnt == 5 ) {
            End = true ;
            return ;
        }
    }

    for( int i = 0 ; i < 5 ; i++ ){
        int cnt = 0 ;
        for( int j = 0 ; j < 5 ; j++ ) {
            if( Vis[j][i] ) cnt++;
            else break ;
        }
        if( cnt == 5 ) {
            End = true ;
            return ;
        }
    }

    int cnt = 0 ;
    for( int i = 0 ; i < 5 ; i++ ) {
        if( Vis[i][i] ) cnt++;
        else break ;
    }
    if( cnt == 5 ) {
        End = true ;
        return ;
    }

    cnt = 0 ;

    for( int i = 0 ; i < 5 ; i++ ) {
        if( Vis[i][4-i] ) cnt++;
        else break ;
    }
    if( cnt == 5 ) {
        End = true ;
        return ;
    }
}
int main() {
    int t ;
    scanf("%d",&t);
    while( t-- ) {
        Pos.clear();
        for( int i = 0 ; i < 5 ; i++ )
            for( int j = 0 ; j < 5 ; j++ ) {
                if( i == 2 && j == 2 ) continue ;
                scanf("%d",&A[i][j] );
                Pos[ A[i][j] ] = make_pair( i, j ) ;
            }
        memset(Vis,false,sizeof Vis);
        End  = false ;
        int Ans = 0 ;
        Vis[2][2] = true ;
        for( int c = 0 ; c < 75 ; c++ ) {
            int x ;
            scanf("%d",&x);
            if( End ) continue ;
            if( Pos.find(x) != Pos.end() ) {
                Vis[ Pos[x].first ][ Pos[x].second ] = true ;
                Check();
            }
            Ans++;
        }
        printf("BINGO after %d numbers announced\n",Ans);
    }
}
