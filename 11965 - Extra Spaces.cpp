#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    int test,n,i,cs=1;
    string s[55],t;
    scanf("%d",&test);
    while(test -- )
    {
        scanf("%d",&n); getchar();
        for( i = 0 ; i < n  ; i++ ){
                getline(cin,t);
                s[i]="";
                int j = 0 , len = t.length() ;
                bool sp = false ;
                if(t[0] == ' ') s[i] += ' ';
                while(t[j] == ' ' && j < len )j++;

                for( ;  j < len ; j++ ){

                    if(t[j] != ' '){
                            s[i] +=  t[j];
                    }
                    else{
                            while(t[j] == ' ' && j < len )j++;
                            s[i] += ' ';
                            j--;
                    }

                }
        }

        printf("Case %d:\n",cs++);
        for( i = 0 ; i < n ; i++ )cout<< s[i]<<endl;

        if(test)puts("");
    }
    return 0;
}
