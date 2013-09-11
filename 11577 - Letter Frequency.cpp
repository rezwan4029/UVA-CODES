#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char letter[26], msg[201];
    int freq[26],test, i, j, max,len;

    scanf("%d", &test);
    getchar();
    while(test--)
    {
        gets(msg);

        for(i=0; i<26; i++)
            freq[i]=0;

        for(i=0; i<26; i++)
            letter[i]=97+i;

        len=strlen(msg);


        for(i=0; i<len; i++ )
        {
            msg[i]=tolower(msg[i]);

            for(j=0; j<26; j++)
            {
                if(msg[i]==letter[j])
                    freq[j]++;
            }
        }

        max=-1;

        for(i=0; i<26; i++)
        {
            if(freq[i]>max)
                max=freq[i];
        }
        for(i=0; i<26; i++)
        {
            if(freq[i]==max)
                printf("%c",letter[i]);
        }
        printf("\n");
    }
}
