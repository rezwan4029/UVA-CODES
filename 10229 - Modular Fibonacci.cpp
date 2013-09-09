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
#define SZ 2
#define ll long long
ll M ;

struct Matrix{
    ll mat[SZ][SZ];
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

void Zero(Matrix &A)
{
    for(int i = 0 ; i < SZ; i++)
        for(int j = 0 ; j < SZ ; j++)
            A.mat[i][j]=0;
}
void Identity(Matrix &A)
{
    for(int i = 0 ;i < SZ ; i++)
        for(int j = 0 ; j < SZ; j++)
            A.mat[i][j]= i == j ? 1 : 0 ;
}
int main()
{
    int test , cs = 1 ,n;
    Matrix Base = {
                    1 , 1,
                    1 , 0
                  };
    while(scanf("%d %lld",&n,&M)==2)
    {
       M = 1LL << M ;
       int ans = 0 ;
       if(n > 1 ){
            Matrix ret = matExpo(Base,n-1);
             ans =  ret.mat[0][0] ;
       }
       printf("%lld\n",ans);
    }
}
