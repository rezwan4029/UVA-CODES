#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int SumOfDivisors(int x)
{
    if(x == 1) return 1;
    int  i,ans = 1,sq=sqrt(x);
    for(i = 2;i <= sq;i ++)
    {
        if( x % i == 0)
            if(i*i == x) ans+=i;
            else ans+=i+x/i;
    }
   return ans+x;
}
int main()
{
    int n ;
    int ans[1001];
    memset(ans,-1,sizeof ans);
    for(int i = 1 ; i<= 1000 ;  i++)
    {
        int x = SumOfDivisors(i);
        if(x<=1000) ans[x] = i;
    }
    int cs = 1 ;
    while(cin>>n && n) printf("Case %d: %d\n",cs++,ans[n]);
}
