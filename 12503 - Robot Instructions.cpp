#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins[105];
char s[10];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,i;
        int res = 0;
        scanf("%d",&n);
        for(i = 1 ;i<= n;i++)
        {
           scanf("%s",&s);
           if(s[0]=='L') {
               res--;
               ins[i] = 1;
           }
           else if(s[0] == 'R'){
                res++;
                ins[i] = 2;
           }
           else{
              scanf("%s %d",&s,&x);
              if(ins[x] == 1 ) res--;
              else  res++;
              ins[i] = ins[x];
           }
        }
        printf("%d\n",res);

    }
    return 0;
}
