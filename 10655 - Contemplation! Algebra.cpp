/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
//#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const int SZ = 2 ;

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
                C.mat[i][j]= C.mat[i][j] + A.mat[i][k] * B.mat[k][j] ;
            }
        }
    return C;
}

Matrix matExpo(Matrix BASE,ll p) // X^p
{
    if(p == 1 )return BASE;
    Matrix R = matExpo(BASE, p/2 );
    R = matMul(R,R);
    if(p&1) R = matMul(R,BASE);
    return R;
}

int main()
{
    Matrix Base ;
    ll p , q , n ;
    while( cin >> p >> q >> n )
    {
        /*
       if( n == 1 ){
             printf("%d\n",p);
             continue;
       }*/
       if( n == 0 ){
             printf("2\n");
             continue;
       }
       Base.mat[0][0] = p ;
       Base.mat[0][1] = -q ;
       Base.mat[1][0] = 1 ;
       Base.mat[1][1] = 0 ;

       Matrix ret = matExpo(Base,n);
       /*
       for( int i = 0 ; i < SZ ; i++ ){
            for(int  j = 0 ; j < SZ ; j++ )
                 cout << ret.mat[i][j] << "  ";
                 cout << endl;
       }*/
       ll ans =  ret.mat[1][0] * p  + ret.mat[1][1] * 2  ;
       printf("%lld\n",ans);
    }
}
