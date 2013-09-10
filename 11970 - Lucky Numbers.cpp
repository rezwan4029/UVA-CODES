#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#define all(x) sort(x.begin(),x.end())
#define sqr(a) (a)*(a)
#include<math.h>
#include<stdio.h>
#include<map>
#define LL long long
#define lim 1000000000
#define SQlim 31623
int main()
{
    LL n,x,k;

    int t,cs=1;
    vector<LL>v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        v.clear();
        for ( k = 1; k <= SQlim; k++ )
            {
                x = n - sqr(k);
                if(x<=0)break;
                if ( x % k == 0) v.push_back (x);

            }
        all(v);
        printf("Case %d:",cs++);
        for(x=0;x<v.size();x++)cout<<" "<<v[x];
        cout<<endl;
    }

    return 0;
}
