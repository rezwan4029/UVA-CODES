#include<stdio.h>
#include<string.h>
char msg[100000],str[10000];
int i,test,quarey,k,len,L,j,p;

int match()
{
    for(i=0; i<len; i++)
    {
        if(str[0]==msg[i])
        {
            p=i+1;

            for(j = 1; j < L; j++)
            {
                if(msg[p] != str[j])
                {
                    return 0;
                }
                p++;
            }
            break;
        }
    }
    return 1;

}
int main()
{

    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",&msg);
        len=strlen(msg);
        scanf("%d",&quarey);
        for(k=0; k<quarey; k++)
        {
            scanf("%s",&str);
            L=strlen(str);
            if(match())printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
