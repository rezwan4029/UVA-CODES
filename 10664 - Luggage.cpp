#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define ll long long
#include <sstream>
using namespace std;

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

int n,sum;
int Lug[25];
int dp[205];

vector<string>token( string a, string b )
{
    const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;
    vector<string>oot; while( *q ) { const char *e = q;while( *e && !count( b.begin(), b.end(),*e ) ) e++;
    oot.push_back( string( q, e ) );q = e; while( count( b.begin(),b.end(), *q ) ) q++;} return oot;
}

void input()
{
    sum = 0;
    char G[5050];
    gets(G);
    vector<string>ret = token(G," ");
    n = ret.size();
    vector<string>::iterator it;
    int i = 0;
    for( it = ret.begin() ; it != ret.end() ; it++ ){
            Lug[i] = toInt( *it );
            sum += Lug[i];
            i++;
    }
}
int main()
{
    int T,i,j;
    scanf("%d",&T); getchar();
    while(T--)
    {
        input();

        memset(dp,0,sizeof dp);

        dp[0]=1;
        for( i = 0 ; i < n ; i++ )
                for( j = sum ; j >=0 ; j-- ){

                    if( dp[j] &&  (j + Lug[i] <= 200) )  dp[ j + Lug[i] ] = 1;
        }

        if(sum&1)puts("NO");
        else{
                if(dp[sum/2])puts("YES");
                else puts("NO");
        }
    }
}
