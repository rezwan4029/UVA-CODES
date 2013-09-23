/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

#define SZ 505

int N , M , I ;
int age[SZ];
vector<int>E[SZ],Par[SZ];
int p[SZ];
bool Vis[SZ];
int ans;

void dfs(int u , int v){
    Vis[u] = true ;
    Par[v].pb(u);
    forstl(it,E[u]){
        if(!Vis[ *it ] ) dfs(*it,v);
    }
}

void Reset(){
   For(i,N){
        E[i].clear();
        Par[i].clear();
        p[i] = i ;
   }
}
int main()
{
    freopen("in.txt", "r", stdin);
    while( scanf("%d %d %d",&N,&M,&I) == 3 )
    {
        Reset();
        For(i,N) age[i] = II;
        rep(i,M){
            int x = II , y = II ;
            E[y].pb(x);
        }
        For(i,N){
            ms(Vis,false);
            Vis[i] = true ;
            forstl(it,E[i]){
                if( !Vis[*it] ) dfs(*it,i);
            }
        }
        while(I--)
        {
            string ins ;
            int x , y ;
            cin >> ins ;
            if(ins == "P" ){
                ans = INF;
                x = II ;
                x = p[x];
                forstl(it,Par[x]) ans = min( ans , age[*it] );
                if(ans != INF) printf("%d\n",ans);
                else puts("*");
            }
            else{
                x = II , y = II ;
                swap(age[ p[x] ],age[ p[y] ]);
                swap(p[x],p[y]);
            }
        }
    }
}
/*
7 8 9
21 33 33 18 42 22 26
1 2
1 3
2 5
3 5
3 6
4 6
4 7
6 7
P 7
T 4 2
P 7
P 5
T 1 4
P 7
T 4 7
P 2
P 6
6 5 6
10 20 30 40 50 60
1 5
1 4
3 6
2 5
4 5
P 1
P 5
P 6
T 1 6
P 1
P 4
*/
