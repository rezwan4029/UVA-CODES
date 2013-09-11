/*
Author : Rezwanul Islam Maruf
AUST ,CSE
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <iomanip>

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define MAX 105
#define MIN -99999999
#define EPS 1e-9
using namespace std;
typedef long long LL;

int main()
{
    int t,i,cs=1;
    char X[MAX],Y[MAX];
    int j,m,n,c[MAX][MAX];

    while (gets(X) && strcmp(X,"#"))
    {
        gets(Y);
        m = strlen(X);
        n = strlen(Y);
        memset(c,0,sizeof(c));
        FOR(i,m)
            FOR(j,n)
                {
                    if (X[i-1]==Y[j-1])
                        c[i][j]=c[i-1][j-1]+1;
                    else if (c[i-1][j]>=c[i][j-1])
                                    c[i][j]=c[i-1][j];
                    else
                            c[i][j]=c[i][j-1];
                }
        printf("Case #%d: you can visit at most %d cities.\n",cs++,c[m][n]);
    }
    return 0;
}
