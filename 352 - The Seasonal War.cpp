#include<stdio.h>
int dx[]={0, 0,1,1, 1,-1,-1,-1};
int dy[]={1,-1,0,1,-1, 0, 1,-1};
int n;
char c[26][26];
int visited[26][26];

void clr()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            visited[i][j]=0;
}
void makeVisited(int p,int q)
{
    int i,X,Y;
    visited[p][q]=1;
    for(i=0;i<8;i++) {
         X=p+dx[i];
         Y=q+dy[i];
         if(X>=0 && X<n && Y>=0 && Y<n && !visited[X][Y] && c[X][Y]=='1')makeVisited(X,Y);
     }
}

int main() {
    int i,j,war,cs=1;
    while(scanf("%d",&n)==1)
    {
        clr();
        war = 0;
        for(i=0;i<n;i++) scanf("%s",&c[i]);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(c[i][j]=='1' && !visited[i][j]) {
                       war++;
                      makeVisited(i,j);
                }
                
        printf("Image number %d contains %d war eagles.\n",cs++,war);
    }
}
