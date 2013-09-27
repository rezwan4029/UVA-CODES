#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,i,n,cnt,cs=1;
    char a[105],b[10];
    gets(b);
    t=atoi(b);
    while(t--)
    {
        gets(b);
        n=atoi(b);
        gets(a);
        cnt=0;
        for(i=0;i<n;i++)
            if(a[i]=='.')
                {
                    i=i+2;
                    cnt++;
                }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
