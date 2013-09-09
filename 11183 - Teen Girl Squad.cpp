/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <sstream>
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<=n;i++)a[i]=i
#define inf 1000000500
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64  long long
#define u64 unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define SS(s) scanf("%s",&s)
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL  ({i64  a; scanf(" %lld", &a); a;})
#define LU  ({u64  a; scanf(" %llu", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define PII pair <int , int>
#define PLL pair <i64 , i64>

#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)

int cs=1;
//

using namespace std;

#define mx 1005
struct Edge{

    int u , v , cost;

    Edge( int x ,int y ,int z){
        u =x , v = y , cost = z ;
    }
    Edge(){};
}E[40005];

int pre[mx],ID[mx],vis[mx];
int In[mx];
int ChuLiu(int root,int nNodes,int nEdges)
{
    int i,ret = 0;
    while(true) {
        //1. Find the smallest edge
        REP(i,nNodes) In[i] = inf;

         REP(i,nEdges){
            int u = E[i].u;
            int v = E[i].v;
            if(E[i].cost < In[v] && u != v) {
                //This step, you can cut off the ring, identifying each point minimum to edge
                pre[v] = u;
                In[v] = E[i].cost;
            }
        }
         REP(i,nNodes) {
            if(i == root) continue;
            if(In[i] == inf)    return -1;//Except a little not into, you cannot reach it
        }
        //2. ring
        int cntnode = 0;

        msn( ID , -1 ) , msn ( vis ,  -1 ) ;

        In[root] = 0;

         REP(i,nNodes) {    //Mark each ring
                ret += In[i];
                int v = i;
                while(vis[v] != i && ID[v] == -1 && v != root) {
                    vis[v] = i;
                    //vis is marked for all nodes in the ring into the edges
                    // of the points below, 1 1,2,3,4,5,6 are marked as
                    v = pre[v];
                }
                if(v != root && ID[v] == -1) {
                    for(int u = pre[v] ; u != v ; u = pre[u]) {
                        ID[u] = cntnode;
                    }
                    ID[v] = cntnode ++;
                }
        }

        if(cntnode == 0)    break;//No ring

         REP(i,nNodes) if(ID[i] == -1) {
            ID[i] = cntnode ++;
        }
        //3. reduced points, Relabel, adjustments into the weights of the edges of the ring,
        // so that the next round of the cycle identified the minimum edge
         REP(i,nEdges) {

            int v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];

            if(E[i].u != E[i].v)  E[i].cost -= In[v];

        }
        nNodes = cntnode;
        root = ID[root];
    }
    return ret;
}
int main()
{
    int T = II ;
    while(T--)
    {
        int i , nodes = II ,nEdges = II , source = 0 ;
        REP(i,nEdges){
            int u = II ,v = II ,w = II ;
           // u-- , v -- ;
            E[i] = Edge( u ,v ,w );
        }
        int ans = ChuLiu(source ,nodes , nEdges) ;
        printf("Case #%d: ",cs++);
        ans == -1 ? puts("Possums!") : printf("%d\n",ans);
    }
}
