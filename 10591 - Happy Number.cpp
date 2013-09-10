#include<iostream>
using namespace std;
#include<vector>
#define sqr(a) (a)*(a)
#include<math.h>
#include<stdio.h>
#include<map>
#define LL long long
LL calc(LL n)
{
    LL m,sum=0;
    while(n)
    {
        sum+=sqr(n%10);
        n/=10;
    }
    return sum;
}
int main()
{
    LL n;
    bool f;
    map<LL,bool>V;
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        LL num=n;
        V.clear();
        V[n]=true;
        f=true;
        while(1)
        {
            n=calc(n);
            if(n==1) break;
            if(V[n]){f=false;break;}
            V[n]=true;
        }
        if(f)printf("Case #%d: %lld is a Happy number.\n",cs++,num);
        else printf("Case #%d: %lld is an Unhappy number.\n",cs++,num);
    }

    return 0;
}
