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
#define inf 9999999
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

#define MAX 100005

int n;
vector<int>Topo[MAX];
vector<int>Comp;
int V[MAX];
bool flag;

void DFS_VISIT(int u)
{
    V[u]=1;

    for(size_t i=0;i<Topo[u].size();i++)
    {
        if(V[ Topo[u][i] ]==0)DFS_VISIT(Topo[u][i]);

        else  if( V[ Topo[u][i] ]==1)
        {
            flag=false;
            return ;
        }
    }
    Comp.pb(u);
    V[u]=2;

}

bool DFS()
{
     flag=true;
     int i;
     for(i=1;i<=n;i++)
     {
         if( !V[i] )DFS_VISIT(i);
         if( !flag )return false;


     }
    return true;
}

int main()
{
    int t,i,cs=1,m;

    while(n=inpI,m=inpI)
    {
        if(!n && !m)break;

        ms0(V);

        while(m--)
        {
            int u,v;

            cin>>u>>v;

            Topo[u].push_back(v);

        }
        Comp.clear();

       // CS;

        if(DFS())
        {
            //printf("Yes\n");
            for(int it=Comp.size()-1;it>=0;it--)cout<<Comp[it]<<endl;
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }

        for(i=0;i<=n;i++) Topo[i].clear();

    }
    return 0;
}



