#include<cstdio>
#include<stack>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define forstl(i,s) for( __typeof(s.begin())i = s.begin() ; i != s.end() ; i++ )
#define rep(i,s) for( __typeof(s)i = 0 ; i < s ; i++)
int main()
{
    int test , cs = 1 ;
    string s ;
    scanf("%d",&test);
    while(test--)
    {
        cin >> s ;
        int len = s.length();
        int CNT[350]={0};
        int pos =  0 ;
        stack<char>stk;
        printf("Case %d\n",cs++);
        rep(i,len)
        {
            if(!stk.size() || stk.top() != s[i])
            {
                stk.push(s[i]);
                 CNT[ s[i] ]++;
            }
            else
            {
                stk.pop();
                if(stk.size()) CNT[ stk.top() ]++;
            }
        }
        CNT[ s[0] ] --;
        for( int i = 'A' ; i <= 'Z' ; i++ )
        {
            if(CNT[i]) printf("%c = %d\n",i,CNT[i]);
        }
    }
    return 0;
}
