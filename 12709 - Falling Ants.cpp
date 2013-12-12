#include <stdio.h>
#define max(a,b) a > b ? a : b

int n , l , w , h , vol , mxH ;

int main(){
    while( scanf("%d",&n) && n ){
        mxH = vol = 0 ;
        while( n-- ){
            scanf("%d %d %d",&l,&w,&h);
            if( mxH < h ){
                mxH = h ;
                vol = l * w * h ;
            }else if( mxH == h ) vol = max( vol , l * w * h );
        }
        printf("%d\n",vol);
    }
    return 0 ;
}
