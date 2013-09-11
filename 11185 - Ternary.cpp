#include<stdio.h>

void Print(int n)
{
    if(n==0) return;
    Print(n/3);
    printf("%d",n%3);
}

int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        if(n<=-1) break;
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        Print(n);
        printf("\n");
    }

    return 0;
}
