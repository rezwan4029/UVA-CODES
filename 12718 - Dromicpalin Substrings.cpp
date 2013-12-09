#include <stdio.h>
#include <string.h>

char s[1007] ;
int Cnt[30];
int main(){
    //freopen("in.txt","r",stdin);
    int test ;
    scanf("%d",&test);
    for( int cs = 1 ; cs <= test ; cs++){
        scanf("%s",&s);
        int len = strlen(s) ;
        int Ans = 0 ;
        for( int i = 0 ; i < len ; i++ ){
            memset(Cnt,0,sizeof Cnt);
            int odd = 0 ;
            for (int j = i  ; j < len ; j++ ) {
                Cnt [ s[j]-'a' ]++;
                if( Cnt [ s[j]-'a' ] & 1 )odd++;
                else odd--;
                int range = j - i + 1;
                if( (range & 1) && odd == 1  ) Ans ++;
                if( !(range & 1) && odd == 0 ) Ans ++;
            }
        }
        printf("Case %d: %d\n",cs,Ans);
    }
}
