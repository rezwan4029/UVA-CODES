/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

//Algo : KMP Matcher (Knuth-Morris-Pratt )

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

#define SZ 1000005

LL Failure[SZ];
char Text[SZ], Pattern[SZ];
vector<LL>PatternIndex;
void Compute_Prefix_function(char Pattern[])
{
    LL m, k, q;
    m = strlen(Pattern);
    Failure[0] = -1;
    k = -1;
    for(q=1; q<m; q++)
    {
        while( k>=0 && Pattern[k+1] != Pattern[q] )
        {
            k = Failure[k];
        }
        if( Pattern[k+1] == Pattern[q] )
        {
          k++;
        }
        Failure[q] = k;
    }
}


int KMP_Matcher(char Textext[], char Pattern[])
{
    LL n, m, i, q;
    n = strlen(Text);
    m = strlen(Pattern);
    Compute_Prefix_function(Pattern);
    q = -1;
    for(i=0; i<n; i++)
    {
        while( q>=0 && Pattern[q+1]!=Text[i] )
        {
            q = Failure[q];
        }
        if( Pattern[q+1] == Text[i] )
        {
            q++;
        }
    /*    if( q==m-1 )
        {
            PatternIndex.pb( i-m+1 ); //saves the index where pattern starts
            q = Failure[q];
        }*/
    }
    return q;
}

int main()
{
    int cs=1,i,t;
   // getchar();
   // while(t--)
    while( gets(Text))
    {
       // gets(Text);
        PatternIndex.clear();
        memcpy(Pattern,Text,sizeof Text);
        //strrev(Pattern);
        int len=strlen(Text);
        for(i=0;i<len;i++)Pattern[i]=Text[len-i-1];
        //cout<<Pattern<<endl;
        int tail= KMP_Matcher(Text,Pattern);
       // CS;
     //   printf("%d\n",PatternIndex.size());

       // for(size_t i=0;i<PatternIndex.size();i++)cout<<PatternIndex[i]<<endl;
       for(i=strlen(Pattern)-1;i>tail;i--)printf("%c",Pattern[i]);
       printf("%s",Pattern);

       printf("\n");
    }

    return 0;
}
//amanaplanacanalpanama
