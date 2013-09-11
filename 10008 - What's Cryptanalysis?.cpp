#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
    if(a>b)return 1;
    return 0;
}
int main()
{

    int t,cnt[250],k,i,len,m[250],use[30];
    char ch,msg[100];
    while(scanf("%d",&t)==1)
    {
        memset(cnt,0,sizeof(cnt));
        getchar();
        while(t--)
        {
            gets(msg);
            len=strlen(msg);
            for(k=0; k<len; k++)
            {
                if(msg[k] >= 'a' && msg[k] <= 'z' )         cnt[ msg[k] - 97 ]++;
                else if(msg[k] >= 'A' && msg[k] <= 'Z' )   cnt[ msg[k] - 65 ]++;
            }
        }
        memset(use,0,sizeof(use));
        for(i=0; i<26; i++)m[ i ]=cnt[i];
        sort(cnt,cnt+26,cmp);
        for(i=0; i<26; i++)
        {
            if(cnt[i])
            {
                for(k=0; k<26; k++)
                    if(m[k]==cnt[i] && !use[k])
                    {
                        use[k]=1;
                        break;
                    }
                printf("%c %d\n",k+65,cnt[i]);
            }
        }
    }

    return 0;
}
