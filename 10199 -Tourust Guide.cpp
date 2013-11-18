/*
 * Biconnected components, bridges and articulation points of
 * undirected graphs
 */
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define MAXN 10005


int N, counter, seen[MAXN], low[MAXN];
vector<int> adj[MAXN], stk,art_Points;

void dfs(int x, int parent)
{
    int kids = 0, art = 0;

    low[x] = seen[x] = ++counter;
    stk.push_back(x);

    for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); ++it) {
        int y = *it;
        if (y == parent) continue;

        if (seen[y] == 0) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            art |= (low[y] >= seen[x]);
            kids++;

          /*  if (low[y] == seen[y]) {
                printf("Edge (%d, %d) is a bridge.\n", x, y);
            }*/
        } else {
            low[x] = min(low[x], seen[y]);
        }
    }

    if (parent == -1) art = (kids >= 2);

    if (art)
       {
         //printf("Vertex %d is an articulation point.\n", x);
         art_Points.push_back(x);
       }
 /*
    if (low[x] == seen[x])
    {
        printf("Biconnected component:");
        while (true)
        {
            int y = stk.back();
            stk.pop_back();
            printf(" %d", y);
            if (y == x) break;
        }
        printf("\n");
    }
 */
}

int main()
{
    int i, x, y, m,n,t=1;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;

        map<string,int>M;
        map<int,string>Out;
        string s1,s2;
        for(i=1;i<=n;i++)
        {
            cin>>s1;
            M[s1]=i; Out[i]=s1;
        }

        scanf("%d",&m);

        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;

            adj[M[s1]].push_back(M[s2]);
            adj[M[s2]].push_back(M[s1]);
        }
    memset(seen, 0, sizeof(seen));
    counter = 0;
    stk.clear();
    art_Points.clear();

    for (x = 1; x <= n; x++) if (seen[x] == 0) dfs(x, -1);

   if(t>1)printf("\n");

   printf("City map #%d: %d camera(s) found\n",t++,art_Points.size());

   vector<string>OO;

    for(i=0;i<art_Points.size();i++)OO.push_back(Out[art_Points[i]]);

    sort(OO.begin(),OO.end());

    vector<string>::iterator it;

    for(it=OO.begin();it!=OO.end();it++)cout<<*it<<endl;

    for(x=0;x<=n;x++)adj[x].clear();

    }

    return 0;

}
