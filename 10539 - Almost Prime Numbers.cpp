#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1000001;
ll lp[N+1];
ll almostprime[N+1];
bool isprime[N+1];
vector<int> pr;
void seive()
{
    for (ll i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back (i);
            isprime[i] = true;
        }
        for (ll j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j) lp[i * pr[j]] = pr[j];
    }
}
int main()
{
    seive();
    int n = 0 ;
    for(ll i = 2 ; i <= N ;i++ )
    {
        if(isprime[i])
            {
                for( ll j = i*i ; j <= 1000000000000LL ; j*=i ) almostprime[n++] = j;
            }
    }
    ll lo , hi ;
    int test ;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld %lld",&lo,&hi);
        int count = 0 ;
        for(int i = 0 ; i < n ; i++ ) if(almostprime[i]>=lo && almostprime[i]<=hi)count++;
        printf("%d\n",count);
    }
}
