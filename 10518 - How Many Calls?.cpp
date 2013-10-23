/*
    Royal_Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1000000000
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi ;
typedef vector<ll>vl;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )


#define SZ 3
int M ;



struct Matrix{
    int mat[SZ][SZ];
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

Matrix matExpo(Matrix BASE,ll p) // X^p
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
    Matrix Base ;
    Base.mat[0][0] = 1 ;
    Base.mat[0][1] = 1 ;
    Base.mat[0][2] = 1 ;
    Base.mat[1][0] = 1 ;
    Base.mat[1][1] = 0 ;
    Base.mat[1][2] = 0 ;
    Base.mat[2][0] = 0 ;
    Base.mat[2][1] = 0 ;
    Base.mat[2][2] = 1 ;

    int cs = 1 ;
    ll n ,  ans ;
    while( scanf("%lld %d",&n,&M) && (n+M) ){
       if(n == 0 ) ans = 1;
       else if( n == 1 ) ans = 1 ;
       else{
            Matrix ret = matExpo(Base,n-1);
         //   rep(i,SZ)rep(j,SZ) cout << ret.mat[i][j] << endl;
            ans =  ( (ret.mat[0][0] + ret.mat[0][1]) %M + ret.mat[0][2] )  % M ;
       }
       printf("Case %d: %lld %d %lld\n",cs++,n,M,ans);
    }
}
