#include <stdio.h>

int main()
{
    int i, n , t ;
    while ( scanf("%d %d",&n,&t) ){
        if( n == 0 && t == 0 ) break;
        for( i = 0 ; i < n ; i++ ) printf("1");
        puts("");
    }
}
