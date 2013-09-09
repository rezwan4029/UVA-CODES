#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

#define SZ 3
const ll M =  1000000009 ;

struct Matrix{
    ll mat[SZ][SZ];
};
Matrix matMul(Matrix A,Matrix B)
{
    Matrix C;
    rep(i,SZ)
        rep(j,SZ){
            C.mat[i][j] = 0 ;
            rep(k,SZ) C.mat[i][j]=((C.mat[i][j]%M)+(((A.mat[i][k]%M)*(B.mat[k][j]%M))%M))%M;
        }
    return C;
}

Matrix matExpo(Matrix BASE,ll p){
    if(p==1)return BASE;
    Matrix R = matExpo(BASE, p >> 1 );
    R = matMul(R,R);
    if(p&1) R = matMul(R,BASE);
    return R;
}

int main()
{
    int test , cs = 1 ;

    Matrix Base = {
                    1,1,1,
                    1,0,0,
                    0,1,0
                  };
    long long n ;
    while(scanf("%lld",&n) && n )
    {
       if( n == 1 ) {
        puts("0");
        continue;
       }
       Matrix ret = matExpo(Base,n-1);
       /*
       for( int i = 0 ; i < SZ ; i++ ){
            for(int  j = 0 ; j < SZ ; j++ )
                 cout << ret.mat[i][j] << "  ";
                 cout << endl;
       }
        */

       printf("%lld\n",ret.mat[0][1]%M);

    }
}
