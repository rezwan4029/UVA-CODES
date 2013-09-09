#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int prev[200005];
int sum[200005];

int Parent(int i)
{
    if (i == prev[i]) return i;

    return (prev[i] = Parent(prev[i]));
}

int main()
{

    int n,i,T;
    string x,y;
    map<string, int>M;
    
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);

        int people = 1;

        for ( i = 1; i <= 2 * n; i++)
        {
            prev[i] = i;
            sum[i] = 1;
        }
    
        

        M.clear();
        
        while (n--)
        {

            cin >>x>>y;

            int a, b;

            if (!M[x])
            {
                a = people++;
                M[x] = a;
            }
            else   a = M[x];
            
            if (!M[y])
            {
                b = people++;
                M[y] = b;
            }
            else  b = M[y];
            
            int p1 = Parent(a);
            int p2 = Parent(b);
            
            if (p1 != p2)
            {
                sum[p1] = sum[p1] + sum[p2];
                prev[p2] = p1;/* make Union*/

            }
            cout << sum[p1] << endl;
        }
    }
    return 0;
}

