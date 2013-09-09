#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

#define SZ 2
int M ;

struct Matrix{
    int mat[SZ][SZ];
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

Matrix matExpo(Matrix BASE,int p){
    if(p==1)return BASE;
    Matrix R = matExpo(BASE, p >> 1 );
    R = matMul(R,R);
    if(p&1) R = matMul(R,BASE);
    return R;
}

int main()
{
    int test , cs = 1 ;
    int mod[]={10,100,1000,10000};
    Matrix Base = {1,1,1,0};
    scanf("%d",&test);
    while(test--)
    {
       int a,b,n;
       scanf("%d %d %d %d",&a,&b,&n,&M);
       M = mod[M-1];
       Matrix ret = matExpo(Base,n-1);
       /*
       for( int i = 0 ; i < SZ ; i++ ){
            for(int  j = 0 ; j < SZ ; j++ )
                 cout << ret.mat[i][j] << "  ";
                 cout << endl;
       }
        */
       int ans =  ( ( ret.mat[0][0] * b ) % M + ( ret.mat[0][1] * a ) % M ) %M ;
       printf("%d\n",ans);
    }
}
