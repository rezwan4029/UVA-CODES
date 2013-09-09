#include<stdio.h>
int main()
{
    char s[50];
    int cs =1;
    while(scanf("%s",&s))
    {
        if(s[0]=='*')break;
        printf("Case %d: ",cs++);
        if(s[0]=='H')puts("Hajj-e-Akbar");
        else puts("Hajj-e-Asghar");
    }
}
