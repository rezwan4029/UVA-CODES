#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char str[500];

    long int count,word,i;

    while(gets(str))
    {
        count=word=0;

        for(i=0;str[i];i++)
        {
            if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
                word=1;
            else
            {
                if(word==1)count++;

                word=0;
            }

        }
        cout<<count<<endl;

    }
    return 0;
}

