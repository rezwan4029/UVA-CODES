#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int row,col;
char c[505][505];
int  V[505][505];

int dx[]={0, 0, 1,-1};
int dy[]={1,-1, 0, 0};

struct Print
{
    char ch;
    int  rank;

}sol[30];

bool cmp (Print x, Print y)
{
    if ( x.rank  > y.rank ) return true;
    if ( x.rank == y.rank  && x.ch  < y.ch ) return true;
    return false;
}

void dfs(int x,int y)
{
    V[x][y]=1;
    int i;
    for(i=0;i<4;i++)
    {
        int a=x+dx[i],b=y+dy[i];

        if(a>=0 && a<row && b>=0 && b<col && !V[a][b] && c[x][y]==c[a][b])dfs(a,b);

    }
}

int main()
{
    int T,cs=1;
    int i,j;
    int CNT[200];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&row,&col);
        for(i=0;i<row;i++)scanf("%s",c[i]);

        memset(V,0,sizeof V);
        memset(CNT,0,sizeof CNT);

        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                {
                    if(!V[i][j])
                    {
                        dfs(i,j);
                        CNT[ c[i][j] ]++;

                    }
                }


        int len=0;
        for(i='a';i<='z';i++)
        {
            if(CNT[i])
            {
                sol[len].ch=i;
                sol[len].rank=CNT[i];
                len++;
            }
        }
       sort(sol,sol+len,cmp);
       printf("World #%d\n",cs++);
       for(i=0;i<len;i++)
       {
           printf("%c: %d\n",sol[i].ch,sol[i].rank);
       }

    }
    return 0;
}
