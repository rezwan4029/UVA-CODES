/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


const int MOD = 10007 ;
const int MX = 107;
int Inv[MX];
int n , m , W , True = 0;
int a[MX] , Fact[MX];
int dp[MX][MX][MX*10];
int Vis[MX][MX][MX*10];
struct Item{
    int freq , val ;
};
Item w[MX];

int solve(int pos , int taken , int currW)
{

    if( pos == m )
    {
        if( currW == 0 ) return Fact[ taken ]; // permute how many times I can take the  taken elements
        return 0 ;
    }
    int &ret = dp[pos][taken][currW];
    if( Vis[pos][taken][currW] == True ) return ret ;
    Vis[pos][taken][currW] = True ;
    ret = 0 ;
    For(i , w[pos].freq )
    {
        int x = currW - i*w[pos].val ;
        if( x >= 0 )
        {
            ret += ( solve(pos+1,taken+i,x) * Inv[i] ) % MOD ; // taking w[pos] with i items
                // as taking duplicate element it should be cut of accorording to permutation rule
            ret %= MOD ;
        }
        else break ;
    }
    ret += solve(pos+1,taken,currW); // taking next element
    ret %= MOD ;
    return ret ;
}


int bigMod(int b ,int p)
{
    int  ret = 1 ;
    while( p > 0 )
    {
        if( p & 1 ) ret = ( ret * b ) % MOD;
        p >>= 1;
        b *= b;
        b %= MOD;
    }
    return ret;
}

void preGen()
{
    Fact[0] = 1 ;
    For(i,MX-6) Fact[i] = (Fact[i-1] * i ) % MOD ;
    rep(i,MX-6) Inv[i] = bigMod(Fact[i],MOD-2);
}

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif

    preGen();

    int test = II ;
    For(cs,test)
    {
        n = II , W = II ;
        rep(i,n) a[i] = II ;
        sort(a,a+n);
        m = 0 ; ++True;
        w[m].val = a[0];
        w[m].freq = 1 ;
        m++;
        For(i,n-1)
        {
            if( a[i] == a[i-1] ) ++w[m-1].freq; // Mth item reamin how many items
            else
            {
                w[m].val = a[i] ;
                w[m].freq = 1 ;
                m++;
            }
        }
        // now M holds the total distinct element number

        int Sum = 0 , Ans = 0 , Prev = 1 , taken = 0 , left ;

        rep(i,m) // taking distinct element i
        {
            left = W - Sum ;
            if( left < 0 ) break ;
            rep( j , w[i].freq ) // number of duplicate element of i
            {
                    left = W - Sum - j * w[i].val;
                    // sum is the current weight of the bag which have been filled
                    // taking j times the w[i] element
                    // so bag reamins only the value of "left"

                    if(left < 0 ) break; // if extra added so , left is < 0 . then take the next element

                    for(int k = left ; k >= 0  &&  k > left - w[i].val  ; k-- ) // left must be >= 0 and taking element must be fill inside of left weight
                    {
                            int tmp = ( solve( i + 1 , taken + j , k ) * Inv[j] ) % MOD ;  // now solve dp in the left weight
                            // see : we have already inserted k weight with (taken+j) items then fill the rest of W in dp
                            tmp *= Prev;
                            tmp %= MOD;
                            Ans = ( Ans + tmp) % MOD;
                    }
            }
            Sum += w[i].val * w[i].freq ; // filling with all the duplicate element
            taken += w[i].freq; // as taking all the duplicate element of Ith weight . so taken += freq of ith item
            Prev = ( Prev * Inv[ w[i].freq ] )% MOD; // doing permutation for duplicate element
        }
        printf("Case %d: %d\n",cs,Ans);
    }
}
