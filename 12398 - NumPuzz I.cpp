#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define i64 long long
using namespace std;
#define rep(i,n) for( __typeof(n) i = 0 ; i < n ; i++ )
#define For(i,n) for( __typeof(n) i = 1 ; i <= n ; i++ )
#define forstl(i,n) for( __typeof(n.begin()) i = n.begin() ; i!= n.end() ; i++ )
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
char s[266];
int out[4][4];
void set(int x ,int y)
{
     out[x][y]++;
     rep(i,4)
     {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < 3 && ny < 3 )out[nx][ny]++;
     }
}
int main()
{
  int cs = 1 ;
  while(gets(s))
  {
    int len = strlen(s);
    memset(out,0,sizeof out);
    rep(i,len){
             if(s[i] == 'a') set(0,0);
        else if(s[i] == 'b') set(0,1);
        else if(s[i] == 'c') set(0,2);
        else if(s[i] == 'd') set(1,0);
        else if(s[i] == 'e') set(1,1);
        else if(s[i] == 'f') set(1,2);
        else if(s[i] == 'g') set(2,0);
        else if(s[i] == 'h') set(2,1);
        else if(s[i] == 'i') set(2,2);
    }
    printf("Case #%d:\n",cs++);
    rep(i,3){
               rep(j,3)
               {
                  if(j)printf(" ");
                   cout<< out[i][j]%10;
               }
               cout << endl;
            } 
    }   
}
