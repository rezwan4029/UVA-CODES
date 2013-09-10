#include<stdio.h>
#include<string.h>
char c[205][205];
int  v[205][205];
int dx[]={0,0,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1};
int n,b;

void DFS(int p,int q)
{
    if(p==n-1){ b=1; return;}
    v[p][q]=1;
    int i;
    for(i=0;i<6;i++)
    {
        int x=p+dx[i];
        int y=q+dy[i];
        if(x>=0 && y>=0 && x<n && y<n && c[x][y]=='b' && !v[x][y])DFS(x,y);
    }
}

int main()
{
    int i,j;
    int cs=1;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++) scanf("%s",&c[i]);
        memset(v,0,sizeof(v));

        b=0;
        for(i=0;i<n;i++)
                    if(c[0][i]=='b' && !v[0][i] && !b) DFS(0,i);


        if(!b)printf("%d W\n",cs++);
        else printf("%d B\n",cs++);
    }
    return 0;
}
