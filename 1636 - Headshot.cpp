#include <stdio.h>
#include <string.h>
char Str[10000000];
int main(){
    int len  , i , Cnt , N ;
    while( gets(Str) ){
        len = strlen(Str);
        N = Cnt = 0 ;
        for( i = 0 ; i < len ; i++ ){
            if( Str[i] == '1' ) continue ;
            N++;
            if( Str[(i+1)%len] == '0')Cnt++;
        }
        if( Cnt*len == N*N ) puts("EQUAL");
        else if( Cnt*len > N*N ) puts("SHOOT");
        else puts("ROTATE");
    }
}
