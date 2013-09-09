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

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define pinf 99999999
#define ninf -99999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define LL long long
#define LLU unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define inpI ({int a; scanf(" %d", &a); a;})
#define inpD ({DB a; scanf(" %lf", &a); a;})
#define inpLL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int GCD(int a,int b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
void SWAP(int &a,int &b){ a = a ^ b; b = a ^ b ;a = a ^ b; }
LL Pow(int B,int P){    LL R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
int BigMod(LL B,LL P,LL M){ LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (LL)R;} //compute b^p%m

vector<int>V[100002];
int vis[100002];
vector<int>Order;
//vector<int>component;
void dfs1(int u)
{
    vis[u]=true;
    for(size_t i=0;i<V[u].size();i++)
    {
        if(!vis[ V[u][i] ]) dfs1(V[u][i]);
    }
    Order.push_back(u);

}
void dfs2(int u)
{
    vis[u]=true;
    //component. push_back( u ) ;

    for(size_t i=0;i<V[u].size();i++)
    {
        if(!vis[ V[u][i] ]) dfs2(V[u][i]);
    }
}
int main ()
{
int num,m,T,cs=1;
cin>>T;
    while (T--)
    {
        cin >> num>>m;
      int adj,u,v,i;

       memset(vis,0,sizeof vis);
       memset(V,0,sizeof V);
       Order.clear();

      while(m--)
      {
          cin>>u>>v;
          V[u].push_back(v);
      }
      for(i=1;i<=num;i++)
                        if(!vis[i])dfs1(i);
   //   for(size_t i=0;i<Order.size();i++)
    //  cout<<Order[i]<<" ";


     // printf("\n");

      memset(vis,false,sizeof vis);
    //  component.clear();
int cnt=0;
      for ( i = 0 ; i < num ;i++ )
      {
        u = Order[ num - 1 - i ] ;
        if ( ! vis[u] ) dfs2 (u) ,cnt++;
      }

   // for(size_t i=0;i<component.size();i++)
   //   cout<<component[i]<<" ";
   //   printf("\n");

    //  printf("Case %d: %d\n",cs++,cnt);
     printf("%d\n",cnt);

    }
    return 0;
}



