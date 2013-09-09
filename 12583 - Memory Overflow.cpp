#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int find(queue<char>q,char x)
{
    while(!q.empty())
    {
        if( q.front() == x) return 1;
        q.pop();
    }
    return 0;
}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        queue<char>q;
        int len,k,ret = 0;
        char s[502];
        scanf("%d %d",&len,&k);
        scanf("%s",&s);
        for(int i = 0 ; i < len ; i++){

            ret += find(q,s[i]);
            q.push(s[i]);
            if(q.size()> k )q.pop();
        }
        printf("Case %d: %d\n",cs++,ret);
    }
    return 0;
}
