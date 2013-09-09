#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#define INF 9999
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++ )
#define forstl(i,n) for(__typeof(n.begin()) i = n.begin() ; i != n.end() ; i++)
typedef  long long int ll;

int C , D , H , S ;

double dp[17][17][17][17][5][5];
bool  vis[17][17][17][17][5][5];

double solve(int club,int dice ,int heart,int spade ,int J1 , int J2 )
{

    if(club < 0 || dice < 0 || heart < 0 || spade < 0 ) return 0.00;


    int c = 13 - club  + (J1 == 1) + (J2 == 1) ;
    int d = 13 - dice  + (J1 == 2) + (J2 == 2) ;
    int h = 13 - heart + (J1 == 3) + (J2 == 3) ;
    int s = 13 - spade + (J1 == 4) + (J2 == 4) ;

    if( c >= C && d >= D && h >= H && s >= S ) return 0.0 ;

    if( (club + dice + heart + spade + (J1==0) + (J2==0) ) == 0 ) return INF;

    double &ret = dp[ club ][ dice ][ heart ][ spade ][ J1 ][ J2 ];
    if( vis[ club ][ dice ][ heart ][ spade ][ J1 ][ J2 ]) return ret ;

    vis [ club ][ dice ][ heart ][ spade ][ J1 ][ J2 ] = true ;


    double remainingCards = ( club + dice + heart + spade + (J1 == 0) + (J2 == 0) );

    ret = 0 ;

    ret += double(club/remainingCards)  * (1. + solve(club-1,dice,heart,spade,J1,J2) ) ;
    ret += double(dice/remainingCards)  * (1. + solve(club,dice-1,heart,spade,J1,J2) ) ;
    ret += double(heart/remainingCards) * (1. + solve(club,dice,heart-1,spade,J1,J2) ) ;
    ret += double(spade/remainingCards) * (1. + solve(club,dice,heart,spade-1,J1,J2) ) ;

    if(J1 == 0 )
    {
        double miniEx = INF ;

        For(i,4)
        {
           miniEx = min ( miniEx ,  double(1./remainingCards) * (1. + solve(club,dice,heart,spade,i,J2) ) );
        }
        ret += miniEx ;
    }

    if(J2 == 0 )
    {
        double miniEx = INF ;

        For(i,4)
        {
           miniEx = min ( miniEx ,  double(1./remainingCards) * (1. + solve(club,dice,heart,spade,J1,i) ) );
        }
        ret += miniEx ;
    }

    return ret ;
}

int main()
{
    int T , cs = 1 ;
    scanf("%d",&T);
    while(T--)
    {

        cin >> C >> D >> H >> S ;

        memset(vis,false,sizeof vis);

        if(C+D+H+S > 54 ) printf("Case %d: -1.000\n",cs++);

        else
        {
            double ret = solve(13,13,13,13,0,0);

            printf("Case %d: %.3lf\n",cs++,ret > 54 ? -1:ret);
        }

    }
    return 0 ;
}
