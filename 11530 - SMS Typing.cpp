#include<stdio.h>
#include<string.h>
int main()
{
    char sms[1000];
    int c,i,j,p,len;
    while(scanf("%d",&c)==1)
    {
        for(j=0; j<=c; j++)
        {
            gets(sms);
            p=0;
            len=strlen(sms);
            for(i=0; i<=len; i++)
            {
                if(sms[i]==' '||sms[i]=='a'||sms[i]=='d'||sms[i]=='g'||sms[i]=='j'||sms[i]=='m'||

                        sms[i]=='p'||sms[i]=='t'||sms[i]=='w') p++;
                else if(sms[i]=='b'||sms[i]=='e'||sms[i]=='h'||sms[i]=='k'||sms[i]=='n'||sms[i]=='q'||

                        sms[i]=='u'||sms[i]=='x') p=p+2;
                else if(sms[i]=='c'||sms[i]=='f'||sms[i]=='i'||sms[i]=='l'||sms[i]=='o'||sms[i]=='r'||sms[i]

                        =='v'||sms[i]=='y') p=p+3;
                else if(sms[i]=='s'||sms[i]=='z') p=p+4;

            }
            if(j!=0) printf("Case #%d: %d\n",j,p);
        }
    }
    return 0;
}

