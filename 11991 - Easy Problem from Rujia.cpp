#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#define  sz 1000005

using namespace std;

vector<int>occur[sz];

int main ()
{
    int n,Q,i,k,x;

    while (scanf("%d %d", &n, &Q)==2)
    {
        memset(occur,0,sizeof occur);

        for ( i = 1; i <= n; i++ )
        {
            scanf ("%d",&x);
            occur [ x ].push_back (i);
        }

        while(Q--)
        {
            scanf ("%d %d",&k, &x);

            if ( occur [x].size () < k ) printf ("0\n");

            else printf ("%d\n", occur [x][k - 1]);
        }
    }

    return 0;
}

