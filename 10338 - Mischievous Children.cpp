#include <stdio.h>
#include <string.h>
#define ll long long
int main()
{
    int t ,cs  = 1 ;
    char s[50];
    ll f[25];
    int temp[505];
    f[0]= f[1] = 1;
    for( int i = 2 ; i<= 20 ; i++ ) f[i] = i * f[i-1];
    scanf("%d",&t);
    while(t--)
    {
       scanf("%s",&s);
       int len = strlen(s);
       memset(temp,0,sizeof temp);
       for( int i = 0 ; i < len ; i++ ) temp[ s[i] ]++;
       ll ret = f[len];
       for( int i = 'A' ; i <= 'Z' ; i++ ) if(temp[i] > 1 )ret /= f[ temp[i] ];
       printf("Data set %d: %lld\n",cs++,ret);
    }
}
