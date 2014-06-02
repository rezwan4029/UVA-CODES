#include <bits/stdc++.h>
using namespace std ;


int NN = 2 ; // Matrix SIZE
//int M = 10; // MOD
const int MATSIZE = 5 ;

struct Matrix{
    double mat[MATSIZE][MATSIZE];
};
Matrix Base;

Matrix matMul(Matrix A,Matrix B) {
    Matrix C;
    for(int i = 0 ; i < NN ; i++)
        for(int j = 0 ;j < NN ;j++) {
            C.mat[i][j] = 0 ;
            for(int k = 0 ; k < NN ;k++){
                C.mat[i][j]= C.mat[i][j] + A.mat[i][k] * B.mat[k][j] ;
            }
        }
    return C;
}

Matrix matAdd(Matrix A,Matrix B) {
    Matrix C ;
    for (int i = 0; i < NN; i++)
        for (int j = 0; j < NN; j++)
            C.mat[i][j] = ( A.mat[i][j] + B.mat[i][j] ) ;
    return C;
}

Matrix matPow(int p) {
    if(p==1)return Base;
    Matrix R = matPow(p >> 1 );
    R = matMul(R,R);
    if(p&1) R = matMul(R,Base);
    return R;
}

int read(int &x){
    #define gc getchar
    int c = gc();
    int sgn=1;
    while(~c && c < '0' || c > '9' ) {
        if(c == '-' ) sgn = -1;
        c = gc();
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = gc() ) x = x*10 + c - '0' ;
    x *= sgn;
    return ~c;
}

int main() {
    int T ; read(T);
    while( T-- ){
        int f0 , f1 , n ;
        double a , b ;
        read(f0) , read(f1) ;
        scanf("%lf %lf",&a,&b);
        read(n) ;
        if( n == 0 ) printf("%d\n",f0);
        else if( n == 1 ) printf("%d\n",f1);
        else {
            Base.mat[0][0] = a ;
            Base.mat[0][1] = b ;
            Base.mat[1][0] = 1 ;
            Base.mat[1][1] = 0 ;

            Matrix R = matPow( n - 1 ) ;
            double Ans = R.mat[0][0] * f1 + R.mat[0][1] * f0 ;
            printf("%0.lf\n",Ans);
            /*
            for( int i = 0 ; i < 2 ; i++ ){
                for( int j = 0 ; j < 2 ; j++ ) printf("%Longd ",R.mat[i][j]);
                puts("");
            }*/
        }
    }
}
