#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
double f(char x)
{
    if(x=='W') return 1.00;
    if(x=='H') return 0.5;
    if(x=='Q') return 0.25;
    if(x=='E') return 0.125;
    if(x=='S') return 0.0625;
    if(x=='T') return 0.03125;
    if(x=='X') return 0.015625;


}
int main ()
{
    char s[55555];
    while(gets(s))
    {
        if(s[0]=='*')break;

        int len = strlen(s);

        int correct = 0;
        double sum = 0;
        for( int i = 1 ; i < len ; i++)
        {
            if( s[i] == '/'){
                if(sum == 1.00 )correct++;
                sum = 0;
            }
            else{
                    sum = sum + f(s[i]);
                    //cout << f(s[i])<<"  ";
            }
        }
        cout<<correct <<endl;
    }

}
