/*
Author : Rezwanul Islam Maruf
AUST ,CSE
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
#include <iomanip>

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define MAX 99999999
#define MIN -99999999
#define EPS 1e-9
using namespace std;
typedef long long LL;



struct lists {
    int start;
    int end;
    int distance;
} a [79810];       // total number of edges

int parent [410];
int vertex;     // number of vertex
int edges;      // number of edges



bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

int main ()
{
    int i,p,q,selectedEdges,mst,wg;
    string s,t;
    while ( scanf ("%d %d", &vertex, &edges) )
    {
        
        if ( vertex == 0 && edges == 0 ) break;

        map < string, int > cityIndex;
        for(i=1;i<=vertex;i++)parent[i]=i;

        for ( i = 0; i < vertex; i++ ) {

            cin >> s;
            cityIndex [s] = i + 1;
        }



        for ( i = 0; i < edges; i++ )
        {
            cin >> s >> t >> wg;
            a [i].start = cityIndex [s];
            a [i].end = cityIndex [t];
            a [i].distance = wg;
        }


        cin >> s;

        sort (a, a + edges, cmp);

         mst = 0;
         selectedEdges = vertex - 1;

        for (i = 0; i < edges && selectedEdges; i++ )
        {
             p = parentOf (a [i].start);
             q = parentOf (a [i].end);

            if ( p != q )
                {
                    parent [p] = q;
                    selectedEdges--;
                    mst += a [i].distance;
                }
        }

        if ( selectedEdges ) printf ("Impossible\n");
        else printf ("%d\n", mst);
    }

    return 0;
}


