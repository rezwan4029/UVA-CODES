#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    int i,lenA,lenB,flag,err;
    char a[100],b[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",&a,&b);
        lenA=strlen(a);
        lenB=strlen(b);
        if(lenA==lenB)
        {
             for(i=0;i<lenA;i++)
                    if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o'|| a[i]=='u')a[i]='a';
             for(i=0;i<lenB;i++)
                    if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o'|| b[i]=='u')b[i]='a';
             err=0;
             for(i=0;i<lenA;i++)
                if(a[i]!=b[i]){err=1;break;}
            if(err) printf("No\n");
            else       printf("Yes\n");

        }
        else printf("No\n");
    }
}
