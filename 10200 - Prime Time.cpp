#include <stdio.h>
#include <math.h>
#include <string.h>
#define sz 10000
int s[sz+10];


int f(int n)
{
    return (n*n+n+41);
}

int check(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

int main()
{
    int i,n;
    s[0]=0;
    for(i=0;i<=10000;i++)
    {
        s[i+1]=s[i];
        if(check(f(i)))s[i+1]++;
    }
    //for(i=0;i<=50;i++)printf("%d ith-> %d\n",i,s[i]);
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        double ans=double(s[b+1]-s[a])/double(b-a+1);
        printf("%.2lf\n",ans*100.00+1e-6);
    }
    return 0;
}
