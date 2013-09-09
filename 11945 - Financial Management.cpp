#include <stdio.h>
typedef long long ll ;
int main(){
    int i , test , cs = 1 ;
    scanf("%d",&test);
    while(test--){
        double x , sum = 0 , num ;
        for(i = 0 ; i < 12 ; i++ ){
            scanf("%lf",&x);
            sum += x ;
        }
        sum /= 12.00 ;
        ll avg = sum ;
        ll en = avg % 1000 ;
        avg /= 1000 ;
        num = sum - ll( sum ) ;
        printf("%d $",cs++);
        if( avg > 0 ) printf("%lld,",avg);
        printf("%.2lf\n",en + num );
    }
}
