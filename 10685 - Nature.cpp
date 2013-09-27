#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
struct E
{
    int u,v;
}xx;
int prev[5005];

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
    int n,r,i,e,M;
    string X,Y;
    int count[5005];
    E x[5005];
    map<string,int>name;
    while(scanf("%d%d",&n,&r))
    {
        if(n==0 && r==0)break;
        for(i = 1 ; i <= n ; i++ ){
                    cin >> X;
                    name[X]=i;
        }
        for(i = 1 ; i <= r ; i++ ){
                cin >> X >> Y;
                x[i].u = name[X];
                x[i].v = name[Y];
        }
        for(i = 1 ; i <= n ; i++ ) count[i] = 0;
        for(i = 1 ; i <= n ; i++ ) prev[i] = i;

        for(i = 1 ; i <= r ; i++ )
                makeUnion(x[i].u,x[i].v);
               
        for(i = 1 ; i <= n ; i++ ) count[ Parent(i) ]++;
       
        M=0;
        for(i = 1 ; i <= n ; i++ ){
                if(M < count[i])
                M = count[i];
        }
        printf("%d\n",M);
    }
    return 0;
}
