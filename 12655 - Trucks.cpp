/*
    Rezwan_4029
    AUST , CSE-25
*/
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


#define mx 100007
int n;
vector< pair<int,int>  >E[mx];
bool V[mx];
int P[mx][22],MIN[mx][22],L[mx],D[mx];

void dfs(int u)
{
    V[u] = true;
    forstl(it,E[u])
    {
        int v = it->first;
        if(!V[ v ])
        {
            D[v] =  it->second ;
            P[v][0] = u;
            MIN[v][0] = D[v];
            L[v] = L[u] + 1;
            dfs(v);
        }
    }
}

void Preprocess()
{
  int i,j;

  for(j = 1; (1 << j) < n; j++)
  {
        for(i = 0; i < n; i++){
                if(P[i][j-1] != -1){
                    P[i][j] = P[ P[i][j-1] ][j-1];
                    MIN[i][j] = min( MIN[i][j-1], MIN[ P[i][j-1] ][j-1]);
                }
        }
  }

}

int Query(int p ,int q)
{
  int i,log , minpath = INF ;

  //if p is situated on a higher level than q then we swap them

  if(L[p] < L[q]) swap(p,q);

  //we compute the value of [log(L[p)]
  for(log = 0; (1 << log) <= L[p]; log++);
  log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P

  if(L[p] != L[q]){
      for(i = log; i >= 0; i--){
            if(L[p] - (1 << i) >= L[q]){
                minpath = min(minpath, MIN[p][i]);
                p = P[p][i];
            }
        }
    }

  if(p == q) return minpath;

  //we compute LCA(p, q) using the values in P

  for(i = log; i >= 0; i--){
        if(P[p][i] != -1 && P[p][i] != P[q][i]){
            minpath = min(  min(minpath, MIN[p][i]) , MIN[q][i] );
            p = P[p][i];
            q = P[q][i];
        }
    }

    minpath = min( minpath , min(D[p] , D[q] ) );

    return minpath;
}

int prev[mx];

void clear()
{
    rep(i,n)
    {
        prev[i] = i ;
        E[i].clear();
        L[i]  -1;
        V[i] = false;
        rep(j,21) MIN[i][j] = P[i][j] = -1;
    }
}


struct edge{
    int u,v,w;
    edge( int a ,int b, int c){
        u = a , v = b , w = c;
    }
    edge(){};
};

bool operator < ( edge a ,edge b){  return a.w > b.w ; }

int Parent(int i){
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

int isUnion(int a,int b){
    return Parent(a)==Parent(b);
}
void makeUnion(int a,int b ){
    prev[Parent(a)] = Parent(b);
}

void MST(int m){
    edge X[mx];
    rep(i,m)
    {
        int u , v , w ;
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        X[i] = edge(u,v,w);
    }
    sort(X,X+m);
  //  int mst = 0;
    for(int i = 0 , span = 0 ; i < m && span < n -1 ; i++)
    {
        if( isUnion(X[i].u , X[i].v ) == false)
        {
            makeUnion(X[i].u,X[i].v);
          //  mst += X[i].w;
            span++;
            E[ X[i].u ].push_back( make_pair( X[i].v , X[i].w) );
            E[ X[i].v ].push_back( make_pair( X[i].u , X[i].w) );
            //cout << "took - > "<< X[i].w << endl ;
        }
    }
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int m ,Q ;
    while(scanf("%d %d %d",&n,&m,&Q) == 3 )
    {
      clear();
      MST(m);
      L[0] = 0 ;
      dfs(0); // set up the levels
      Preprocess();
      while(Q--)
      {
          int u , v ;
          scanf("%d %d",&u,&v);
          u-- , v-- ;
          int ret = Query(u,v);
          printf("%d\n",ret);
      }
    }
}
