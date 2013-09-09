/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include<queue>
#define pb push_back
#define INF 1<<30
#define CS printf("Case #%d: ",cs++)
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({ll  a; scanf("%lld", &a); a;})
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
#define PI 3.1415926535897932384626433832795
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

int cs = 1 ;

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int row , col ;
char grid[57][57];
bool used[57][57];
bool trap[57][57];

bool isValid(int x , int y ){
     if( x >= 0 && x < row && y >=0 && y < col && grid[x][y] != '#' && !used[x][y]) return true ;
     return false ;
}
struct stype{
       int x ,y ,cost ;
       stype( int _x , int _y ){
              x = _x , y =_y  ;
       }
};
queue< stype > Q ;
void build(){
     ms(trap,false);
     rep(i,row)rep(j,col){
        if( grid[i][j] == 'P' ) Q.push( stype(i,j) ) , used[i][j] = true ;
        if( grid[i][j] == 'T' ){
            trap[i][j] = true ;
            rep(k,4){
                     int nx = i + dx[k];
                     int ny = j + dy[k];
                     if( nx >= 0 && nx < row && ny >=0 && ny < col ) trap[nx][ny] = true;
            }
        }
   }
}
int main()
{
    while( scanf("%d %d",&col,&row) == 2 ){
           rep(i,row) scanf("%s",grid[i]);
           ms(used,false);
           build();
           int ans = 0 ;
           while( !Q.empty() ){
                  stype now = Q.front() ; Q.pop();
                  if( trap[ now.x ][ now.y ] ) continue ;
                  rep(i,4){
                     int nx = now.x + dx[i];
                     int ny = now.y + dy[i];
                     if( isValid(nx,ny) ){
                         if( grid[nx][ny] == 'G') ans++;
                         used[nx][ny] = true ;
                         Q.push( stype(nx,ny) ) ;
                     }
                  }
           }
           printf("%d\n",ans);
                           
    }
}
