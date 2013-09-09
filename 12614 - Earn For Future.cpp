#include<stdio.h>
int main()
{
    int t ,n, cs  = 1  , mx , x ;
    scanf("%d",&t);
    while(t--)
    {
        mx = 0 ;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            if(mx < x ) mx = x ;
        }
        printf("Case %d: %d\n",cs++,mx);
    }
    return 0 ;
}
