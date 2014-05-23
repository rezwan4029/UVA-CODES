#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
bool g[3007][3007];
int main(){
    int N , M , T ;
    scanf("%d",&T);
    while( T-- ){
        scanf("%d %d",&N,&M);
        memset(g,false,sizeof g);
        while(M--){
            int x , y ;
            scanf("%d %d",&x,&y);
            g[x][y] = g[y][x] = true ;
        }
        int Ans = 0 ;
        for( int i = 1 ; i <= N ; i++ ){
            for( int j = i + 1 ; j <= N ; j++ ){
                if( g[i][j] == false ) continue ;
                for( int k = j + 1 ; k <= N ; k++ ){
                    if( g[j][k] and g[k][i] ) Ans++;
                }
            }
        }
        printf("%d\n",Ans);
    }
}
