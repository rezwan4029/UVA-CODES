#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

int prev[30];

int Parent(int i)
{
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

void makeUnion(int a,int b)
{
    prev[Parent(a)] = Parent(b);
}

int main()
{
    int n,i,M,cs=0,t;
    int p,q;
    char c;
    string s;
    int count[30];
    scanf("%d",&t);
    while(t--)
    {
        if(cs)printf("\n");cs=1;

        cin>>c;
        n=c-64;

        for(i=1;i<=n;i++)count[prev[i]=i]=0;
        getchar();
        while(1)
            {
              getline(cin,s);
              if(s.size()==0)break;
              p=s[0]-'A'+1;
              q=s[1]-'A'+1;
              makeUnion(p,q);
            }

        for(i=1;i<=n;i++) count[Parent(i)]++;
        M=0;
        for(i=1;i<=n;i++)
            {
               if(count[i])M++;
            }
        printf("%d\n",M);
    }
    return 0;
}
