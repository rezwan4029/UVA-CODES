#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[100005];
int memo[240];

int max(int p,int q)
{
     if(p > q )  return p ;
     return q;
}
int main()
{
    int t,i,n,x,mx,q;
    scanf("%d",&t);
    while(t--)
    {
        memset(memo,-1,sizeof memo);

        scanf("%d %d",&n,&q);
        for(i = 0 ; i <  n ; i++ )scanf("%d",&a[i]);

        while(q--)
        {
            scanf("%d",&x);
            if(memo[x] == -1 ){
                    mx = 0;
            
                    if(x!=0) for( i = 0 ; i < n ; i++) mx = max( mx , (a[i]&x) );
                    memo[x]=mx;
                    printf("%d\n",memo[x]);
            }
            else printf("%d\n",memo[x]);
        }
    }
    return 0;
}
