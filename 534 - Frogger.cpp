#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int stones,i,j,k;
    int cases = 0;
    double d[205][205];
    int x[205],y[205];

    while ( scanf ("%d", &stones) && stones )
    {

        for (i=0;i<stones;i++) scanf ("%d %d", &x [i], &y [i]);

        for (i=0;i<stones;i++ )
            for (j=i+1;j<stones;j++)
                d[i][j]=d[j][i]=sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) );

        for (k = 0; k < stones; k++ )
            for (i = 0; i < stones; i++ )
                for (j = 0; j < stones; j++ )
                    d [i] [j] = min (d[i] [j], max (d[i][k], d[k][j]));

        printf ("Scenario #%d\nFrog Distance = %.3lf\n\n",cases++,d[0][1]);
    }
    return 0;
}
