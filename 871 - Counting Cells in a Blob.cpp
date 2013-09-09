using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

vector<string>inp;

int row,col,cnt;

int dx[]={-1, 0, 1,1,1,0,-1,-1};
int dy[]={-1,-1,-1,0,1,1, 1, 0};


void DFS(int x, int y)
{
    if(x<0 || x>=row || y<0 || y>=col || inp[x][y]=='0') return;
    
    cnt++;
    inp[x][y]='0';
    
    for(int i=0;i<8;i++) DFS(x+dx[i],y+dy[i]);
}
int main()
{
    int i,j,T,sp=0;
    string str;

    scanf("%d\n\n",&T);
    while(T--)
    {
        inp.clear();
        while(getline(cin,str))
        {
            if(str=="") break;
            inp.push_back(str);
        }
        int res=0;

        col=inp[0].length();
        row=inp.size();

        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                {
                  cnt=0;
                  DFS(i,j);
                  res=max(res,cnt);
                }

     if(sp) printf("\n");
     printf("%d\n",res);
     sp=1;
    }
    return 0;
}

