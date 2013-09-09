#include<stdio.h>
#define min(a,b) (a>b?b:a)
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b))
    {
        if(a<0 && b<0)break;

        if(a>b)
        {
            a=a^b;b=a^b;a=a^b;
        }
        printf("%d\n",min((b-a),(a-b+100)));
    }
    return 0;
}
