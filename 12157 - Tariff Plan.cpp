#include <stdio.h>
int main(){
    int t ;
    scanf("%d",&t);
    for(int cs = 1 ; cs <= t ; cs ++ ){
        int n ; scanf("%d",&n);
        int mile = 0 , juice = 0 ;
        while(n-- ){
                int x ; scanf("%d",&x);
                mile  += ( ( x / 30 ) + 1 ) * 10 ;
                juice += ( ( x / 60 ) + 1 ) * 15 ;
        }
        printf("Case %d: ",cs);
        if(mile < juice )printf("Mile %d\n",mile);
        else if( mile > juice )printf("Juice %d\n",juice);
        else printf("Mile Juice %d\n",mile);
    }
}
