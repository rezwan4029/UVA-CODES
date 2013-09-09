#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
int a[105],n,cs=1;

bool solve()
{
    set<int>s;
    if(a[0]<1)return false;
    rep(i,n-1)if(a[i]>=a[i+1])return false;

    for(int i = 0 ; i < n ; i++)
        for( int j = i  ; j < n ; j++){
        if( s.count(a[i]+a[j]))return false;
        s.insert(a[i]+a[j]);
    }
    return true;
}
int main()
{
    while(cin>>n)
    {
        rep(i,n)cin>>a[i];
        bool ans = solve();
        printf("Case #%d: It %s a B2-Sequence.\n\n",cs++,ans?"is":"is not");
    }
}
