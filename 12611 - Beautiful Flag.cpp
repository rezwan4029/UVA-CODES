#include<stdio.h>

int main()
{
    int t , cs = 1;
    scanf("%d",&t);
    while(t--)
    {
        int R;
        scanf("%d",&R);
        int l = 5*R;
        int x1 = 45 * l / 100 ;
        int x2 = l - x1;
        int y = 60* l /100 ;
        printf("Case %d:\n",cs++);
        x1 > 0 ? x1 :  x1 *=-1 ;
        y > 0 ? y :  y *=-1 ;
        x2 > 0 ? x2 :  x2 *=-1 ;

        printf("%d %d\n",-x1,y/2);
        printf("%d %d\n",x2,y/2);
        printf("%d %d\n",x2,-y/2);
        printf("%d %d\n",-x1,-y/2);

    }
}
