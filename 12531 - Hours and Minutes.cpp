#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1){
        ( n % 6 == 0) ? puts("Y") : puts("N");
    }
    return 0;
}
