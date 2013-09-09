#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

#define N 100000000


#define N 100000000
int lp[N+1];
bool isPrime[N+1];
vector<int> pr;
void seive()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back (i);
            isPrime[i] = true;
        }
        for (int j=0; j< pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j) lp[i * pr[j]] = pr[j];
    }
}

int main()
{
    seive();
    int n , len = pr.size();
    while(scanf("%d",&n)==1)
    {
            bool found = false ;
            if(n < 4 ) printf("%d is not the sum of two primes!\n",n);
            else if( n % 2  == 1 )
            {
                if(isPrime[n-2]) printf("%d is the sum of %d and %d.\n",n,2,n-2);
                else printf("%d is not the sum of two primes!\n",n);
            }
            else
            {
                int i =  int(lower_bound (pr.begin(), pr.end(), n/2) - pr.begin());
                while(pr[i] >= n/2 )i--;
                for( ; i >= 0 ; i-- )
                {
                    int j =  int(upper_bound (pr.begin(), pr.end(), n - pr[i] ) - pr.begin()); j--;
                    if( i != j && pr[i]+pr[j] == n)
                    {
                        printf("%d is the sum of %d and %d.\n",n,pr[i],n-pr[i]);
                        found = true ;
                        break;
                    }
                }
                if(found == false) printf("%d is not the sum of two primes!\n",n);
            }
    }
}
