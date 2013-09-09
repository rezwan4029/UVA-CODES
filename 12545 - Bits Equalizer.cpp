#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{

    int t,cs=1;
    char s[205],p[205];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",&s,&p);
        int i  ;
        int  len = strlen(s);

        int zero = 0 , one = 0 ,ans = 0;

        int z1 = 0 ,o1 = 0 ,z2 =0 ,o2 = 0 ,q = 0;

        for( i = 0 ; i < len ; i++)
        {
            if( s[i]==p[i])continue;
            if(s[i]=='?')ans++;
            if(s[i]=='0' && p[i]=='1')zero++;
            if(s[i]=='1' && p[i]=='0')one++;

            if(s[i]=='1')o1++;
            else if(s[i]=='0')z1++;
            else    q++;

            if(p[i]=='1')o2++;
            else z2++;

        }
        //printf("%d %d %d  \n",zero,one ,ans );
        if( o1 > o2){
         printf("Case %d: -1\n",cs++);
        }
        else {

                ans += zero > one ? zero : one ;
                printf("Case %d: %d\n",cs++,ans);


        }


    }
}
