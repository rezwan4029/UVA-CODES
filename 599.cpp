#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

vector<int>edg[30];
int N , Acrons ;
bool Vis[30];


void Input(){
    string s ;
    map<char,int>Map ;
    int Indx = 0 ;
    while(true){
        char a ,  b ;
        cin >> s ;
        a = s[1] , b = s[3] ;
        if( s[0] == '*' )break ;
        if(!Map[a])Map[a] = ++Indx;
        if(!Map[b])Map[b] = ++Indx;
        edg[ Map[a] ].pb( Map[b] );
        edg[ Map[b] ].pb( Map[a] );
    }
    cin >> s ;
    N =  (s.size()+1) / 2  ;
    Acrons = N - Indx ;
}

void Clr(){
    rep(i,N+1) {
        edg[i].clear();
        Vis[i] = false ;
    }
}
void dfs(int u){
   // printf("%d ",u);
    Vis[u] = true ;
    forstl(it,edg[u]){
        if( Vis[*it] ) continue ;
        dfs(*it);
    }
}
int main(){
    int test = II ;
    For(cs,test){
        Input();
        int Cnt = 0 ;
        For(i,N){
            if(!Vis[i]) {
                dfs(i);
                ++Cnt ;
            }
            //puts("");
        }
        Clr();
        printf("There are %d tree(s) and %d acorn(s).\n",Cnt - Acrons,Acrons);
    }
}