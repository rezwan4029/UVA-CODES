#include<stdio.h>



long prev[50005];

long Parent(long i)
{
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

void makeUnion(long a,long b)
{
    prev[Parent(a)] = Parent(b);
}

int main()
{
    long n,r,i,e,M,cs=1;
    long p,q;

    int count[50005];

    while(scanf("%ld%ld",&n,&r))
    {
        if(n==0 && r==0)break;

        for(i=1; i<=n; i++)count[prev[i]=i]=0;
        for(i=1; i<=r; i++)
        {
            scanf("%ld%ld",&p,&q);
            makeUnion(p,q);
        }

        for(i=1; i<=n; i++) count[Parent(i)]++;
        M=0;
        for(i=1; i<=n; i++)
        {
            if(count[i])M++;
        }
        printf("Case %ld: %ld\n",cs++,M);
    }
    return 0;
}

