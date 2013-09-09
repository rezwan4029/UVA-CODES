#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int prev[1005];

int Parent(int i)
{
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

void makeUnion(int a,int b)
{
    prev[Parent(a)] = Parent(b);
}

int main()
{
    int n,p,q,i;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        getchar();
        for(i=1;i<=n;i++)prev[i]=i;
        char text[20],ch;

        int correct=0,wa=0;

        while(gets(text) && strlen(text))
            {
                sscanf(text,"%c %d %d",&ch,&p,&q);
                if(ch=='c') makeUnion(p,q);
                else
                {
                    int a=Parent(p);
                    int b=Parent(q);
                    if(a==b)correct++;
                    else wa++;
                }
            }


        printf("%d,%d\n",correct,wa);
        if(T)printf("\n");
    }
    return 0;
}
