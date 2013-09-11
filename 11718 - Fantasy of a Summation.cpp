#include <stdio.h>
int sq(int x)
{
    return x * x;
}

long bigmod(long b, long p, long m)
{
    if (p == 0) return 1;
    else if (p%2 == 0) return sq( bigmod (b,p/2,m)) % m;
    return ((b % m) * bigmod( b,p-1,m)) % m;
}
int main()
{
    int ans, k, mod, n, nek1, p, sum, t, x,cs=1;
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d %d %d", &n, &k, &mod);
        p = n;
        sum = 0;
        while(p--)
        {
            scanf("%d", &x);
            sum = (sum + (x % mod)) % mod;
        }
        ans = ((bigmod(n, k - 1, mod) * sum) % mod) * (k % mod);
        printf("Case %d: %d\n", cs++, ans % mod);
    }
    return 0;
}
