#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int S,T,N;
void nwln()
{
    int i,j,p = (N+1)*T + S*N;
    int a = 1;
        for(j = 0 ; j < T ; j++) {
            for( i = 0 ; i < p ;i++)cout<<"*";
            puts("");
        }
}
int main()
{
    int cs = 1;
    while(scanf("%d%d%d",&S,&T,&N))
    {
        if(S==0 && T==0 && N==0)break;
        printf("Case %d:\n",cs++);
        int i,j,k;

        nwln();

        for( i = 0 ; i < N ; i++ )
        {
            for( int x = 0 ; x < S ; x++)
                {
                    int temp = N+1;
                    while(temp--)
                    {
                        for( j = 0 ; j < T ; j++)cout<<"*";
                        if(temp)for( k = 0 ; k < S ; k++)cout<<".";
                    }

                    cout<<endl;
                }
            nwln();
        }
        puts("");
    }
}
