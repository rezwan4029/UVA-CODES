/*
  Rezwan_4029
  AUST, 25th batch
  Catagory : Matrix Exponentiation
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
 
#define ll long long
ll M ;
int SZ ;
struct Matrix{
    ll mat[20][20];
};
Matrix matMul(Matrix A,Matrix B)
{
    Matrix C;
    for(int i = 0 ; i < SZ ; i++)
        for(int j = 0 ;j < SZ ;j++)
        {
            C.mat[i][j] = 0 ;
            for(int k = 0 ; k < SZ ;k++){
                C.mat[i][j]=((C.mat[i][j]%M)+(((A.mat[i][k]%M)*(B.mat[k][j]%M))%M))%M;
            }
        }
    return C;
}
 
void Copy(Matrix &A,Matrix &B)
{
    for(int i = 0 ; i < SZ ; i++)
        for(int j = 0 ; j < SZ ; j++)
            B.mat[i][j]= A.mat[i][j];
}
 
Matrix matExpo(Matrix BASE,int p) // X^p
{
    if(p==1)return BASE;
    Matrix R = matExpo(BASE, p >> 1 );
    R = matMul(R,R);
    if(p&1) R = matMul(R,BASE);
    return R;
}
 
void Identity(Matrix &A)
{
    for(int i = 0 ;i < SZ ; i++)
        for(int j = 0 ; j < SZ; j++)
            A.mat[i][j]= i == j ? 1 : 0 ;
}
int main()
{
    int test , cs = 1 ,n,d;
    Matrix Base ;
    ll F[20];
    while(scanf("%d %d %lld",&d,&n,&M))
    {
       if( n == 0 && d == 0 && M == 0 ) break ;
       SZ = d ;
       memset(Base.mat,0,sizeof Base.mat);
       for( int i = 0 ; i < d ; i++ ) scanf("%lld",&Base.mat[0][i]);
       for( int i = 1 , j = 0 ; i < d ; i++ , j++ ) Base.mat[i][j] = 1 ;
       for( int i = d - 1 ; i >= 0  ; i-- ) scanf("%lld",&F[i]);
       int ans ;
       if(n > d ){
             Matrix ret = matExpo(Base,n-d);
             ans = 0 ;
             for(int i = 0 ; i < d ; i++) ans =(ans +( ret.mat[0][i]%M * F[i]%M ) %M ) %M ;
       }else {
        ans = F[d - n ] % M ;
       }
       printf("%lld\n",ans);
    }
}
