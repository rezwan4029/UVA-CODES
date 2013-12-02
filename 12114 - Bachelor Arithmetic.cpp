#include<stdio.h>

int main()
{
    int CASE=1,B,S;

    while(1)
    {

        scanf("%d%d",&B,&S);

        if(B==0 && S==0)break;

        printf("Case %d: ",CASE++);

        if(B<=1)
            printf(":-\\\n");
        else if(B<=S)
            printf(":-|\n");
        else
            printf(":-(\n");
    }
    return 0;
}
