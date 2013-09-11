

#include <stdio.h>



long prev[30005];
long Parent(long i)
{
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

void makeUnion(long a,long b)
{
    prev[Parent(a)] = Parent(b);
}

int  main()
{
    long t,n,e,i,M;
    long count[30005];
    long x,y;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&e);
        for(i=1; i<=n; i++)count[prev[i]=i]=0;
        for(i=0; i<e; i++)
        {
            scanf("%ld %ld",&x,&y);
            makeUnion(x,y);
        }

        for(i=1; i<=n; i++)
            count[Parent(i)]++;
        M=1;
        for(i=1; i<=n; i++)
        {
            if(M<count[i])M=count[i];
        }
        printf("%ld\n",M);
    }
    return 0;
}
