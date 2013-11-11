#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define i64 long long
#define mx -9999999
using namespace std;

int cities , source,numOfEndings,ending[105];
int edges[105][105];
int dp[105][1005];

int solve(int currNode , int remainingVisited)
{
    int &ret = dp[currNode][remainingVisited];
    if( ret != -1 )return ret;

    ret = mx;

    if(remainingVisited == 1){

            for( int i = 1 ; i <= cities ; i++ ){
                    if( ending[i] ) ret =  max( ret , edges[currNode][i] );
            }
    }
    else{

            for( int i = 1 ; i <= cities ; i++ ){

                    ret = max( ret , edges[currNode][i] +solve(i,remainingVisited - 1 ) ) ;
            }
    }
    return ret ;

}

int main()
{
    int i , j , haveTovisit ;
    while(scanf("%d %d %d %d",&cities,&source,&numOfEndings,&haveTovisit))
    {
        if( cities == 0 && source == 0 && numOfEndings == 0 && haveTovisit == 0 )break;

        memset(ending,false,sizeof ending);

        for( i = 1 ; i <= cities ; i++ )
            for( j = 1 ; j <= cities ; j++)
                    scanf("%d",&edges[i][j]);

        for( i = 0 ; i < numOfEndings ; i++){
            scanf("%d",&j);
            ending[j] = true ;
        }

        memset(dp,-1,sizeof dp);

        int ret = solve(source,haveTovisit);

        printf("%d\n",ret);
    }
    return 0;
}
