#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

int main()
{
    int T,cs=1;
    scanf("%d",&T);
    char s[20];
    getchar();
    while(T--)
    {
        int i,x,y;
        gets(s);
        int len = strlen(s);
        string p,q;
        for( i = 0 ; i < len ; i++ )if( isdigit(s[i] ) )break;
        while( isdigit( s[i] ) ) p+= s[i++];
        for( ;i <len ; i++) if( isdigit(s[i]) )break;
         x =toInt(p);
        if( i == len ) y =0;
        else{
            while( isdigit( s[i] ) ) q+= s[i++];
            y =toInt(q);
        }
        int res = 10*x + y;
        printf("Case %d: ",cs++);
        cout<<double(res)/20<<endl;

    }
}
