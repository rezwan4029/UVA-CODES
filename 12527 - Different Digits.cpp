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


int digit[5002];

int main()
{
    int n,m,i;
    bool use[11];

    for( n = 1 ; n <= 5000 ; n++ )
    {
            memset(use,false,sizeof use);

            m = n;

            while(m)
            {
                if( use[ m%10 ])break;
                use[ m%10 ] = true;
                m/=10;
            }
            if(m==0)digit[n]=1;
            digit[n] += digit[n-1];
    }
    while(scanf("%d %d",&n,&m) == 2){
              printf("%d\n",digit[m] - digit[n-1] );

    }
}
