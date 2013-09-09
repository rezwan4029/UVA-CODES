#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
int d,len;
int ret(char *s)
{
    long n = 0 , i = 0 ;
    while(s[i]) n = n *10 + s[i++] - '0';
    if(n%d == 0) return 1;
    return 0;
}
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        char  s[12] ;
        scanf("%s %d",&s,&d);
        len = strlen(s);
        int ans = 0;
        sort(s,s+len);
        do{ ans+= ret(s); }while(next_permutation(s,s+len));
        printf("%d\n",ans);
    }
}
