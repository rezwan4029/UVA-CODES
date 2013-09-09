#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define mx 5005

int findSwaps( int n, int a[] )
{
    int count = 0, i, j, temp, b[100000];

    for( i = 0; i < n; i++ ) {
        b[i] = a[i];
    }
    for( i = 0; i < n; i++ ) {
        for( j = 0; j < n - 1; j++ ) {
            if( b[j] > b[j+1] ) {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;

                count++;
            }
        }
    }
    return count;
}

void brute(int n)
{
    int b[100000];
    for( int i = 0 ; i < n ; i++ ) b[i] = n-i-1;
    int x = findSwaps(n,b);
    cout<<x;
}
int main()
{
    int cs = 1 , T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        printf("Case %d: ",cs++);
       // brute(n);
       // printf(" ");
       n = n*(n-1);
       if(n%4 == 0 )cout<<n/4;
       else{
            (n&1) ? cout << n <<"/4" : cout << n/2 <<"/2";
       }
        puts("");
    }
}
