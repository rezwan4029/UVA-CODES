#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10005];

int main()
{
    int n = 0;
    while(scanf("%d",&a[n++]) == 1)
    {
        sort(a,a+n);

        !(n & 1) ? printf( "%d\n", (a[n/2] + a[n/2 - 1 ])/2 ) : printf( "%d\n",a[ (n-1)/2 ] );
    }

    return 0;
}
