#include <stdio.h>
int main()
{
    int T,x,y,z;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&x,&y,&z);
        int A = 2 * z * x;
        int B = z * y;
        printf("%d\n",(A-B)/(x+y));

    }
    return 0;
}

   //   printf("%d\n",z*( (x<<1) -y)/(x+y));
