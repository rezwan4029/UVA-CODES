/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 1007;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int r , c ;
bool bomb[MX][MX];
bool Vis[MX][MX];

bool valid(int x , int y){
    return x >= 0 && x < r && y >=0 && y < c && !bomb[x][y] && !Vis[x][y];
}

struct Node{
    int x , y , cost ;
    Node(){}
    Node(int _x , int _y , int _c  ){
        x = _x , y = _y , cost = _c ;
    }
};
Node St, En;
int bfs(){
    ms(Vis,false);
    queue<Node>Q;
    St.cost = 0;
    Vis[St.x][St.y] = true ;
    Q.push(St);
    while(!Q.empty()){
        Node now = Q.front(); Q.pop();
        if( En.x == now.x  && En.y == now.y ) return now.cost ;
        rep(i,4){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if( valid(nx,ny)){
                Vis[nx][ny] = true ;
                Q.push( Node(nx,ny,now.cost + 1) );
            }
        }
    }
}
int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    while( scanf("%d %d",&r,&c)){
        if( r == 0 && c == 0 ) break ;
        int B = II ;
        ms(bomb,false);
        rep(i,B){
            int rNo = II ;
            int n = II ;
            rep(x,n){
                int cNo = II ;
                bomb[rNo][cNo] = true ;
            }
        }
        scanf("%d %d",&St.x,&St.y);
        scanf("%d %d",&En.x,&En.y);
        int Ans = bfs();
        printf("%d\n",Ans);
    }
}
