/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include <queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)


int x[9], a, b, sol ;

bool place(int queen, int row)
{
    for (int prev = 1; prev < queen; prev++)
        if (x[prev] == row || abs(x[prev] - row) == abs(prev - queen))
            return false;
    return true;
}

void back(int queen)
{
    if (queen == 9)
    {
        if (x[b] == a)
        {
            printf("%2d      %d",sol++, x[1]);
            for (int i = 2; i <= 8; i++)
            {
                printf(" %d", x[i]);
            }
            puts("");
        }
    }
    else
    {
        for (int row = 1; row <= 8; row++)
        {
            if (place(queen, row))
            {
                x[queen] = row;
                back(queen + 1);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &a, &b);
        ms(x,0);
        sol = 1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        back(1);
        if (t) puts("");
    }
    return 0;
}
