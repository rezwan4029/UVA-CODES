#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;

struct point{int x,y;};
point P[55];

bool cmp(point a , point b)
{
    return atan2(a.x,a.y) > atan2(b.x,b.y);
}

int dp[52][52][2502];
bool v[52][52][2502];

int solve(int currPos , int taken , int Ysum )
{
    if(taken == 0 || currPos < 0 )return 0 ;


    int &ret =  dp[ currPos ][ taken ][ Ysum ] ;

    if(v[ currPos ][ taken ][ Ysum ] )return ret;

    v[ currPos ][ taken ][ Ysum ] = true;


    ret = solve(currPos - 1,taken,Ysum);

    ret = max( ret , solve(currPos-1, taken - 1 , Ysum + P[currPos].y ) + 2*Ysum * P[currPos].x + P[currPos].x * P[currPos].y );

    return ret ;
}

int main()
{
    int T,n,k,cs=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for( int i = 0 ; i < n ; i++ )scanf("%d %d",&P[i].x,&P[i].y);
        sort(P,P+n,cmp);
        memset(v,false,sizeof v);
        // for( int i = 0 ; i < n ; i++ ) printf("%d  %d\n",P[i].x,P[i].y);
        int ret = solve(n-1,k,0);
        printf("Case %d: %d\n",cs++,ret);
    }
    return 0;
}
