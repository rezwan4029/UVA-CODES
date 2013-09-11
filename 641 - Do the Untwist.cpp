#include<stdio.h>
#include<string.h>
char codes[29]="_abcdefghijklmnopqrstuvwxyz.";
int conv(char c)
{
    int i;
    for(i=0;i<28;i++)if(codes[i]==c)return i;
}
int main()
{
    int k,i,len,index,m;
    char msg[82];

    int plaintext[82];
    while(scanf("%d",&k) && k)
    {
        scanf("%s",&msg);
        len=strlen(msg);

        for(i=0;i<len;i++)
        {
            m=conv(msg[i]);
            index=(k*i) % len ;
            plaintext[ index ] =(m+i)%28;
        }
        for(i=0;i<len;i++)printf("%c",codes[ plaintext[i] ]);printf("\n");
    }
    return 0;
}
