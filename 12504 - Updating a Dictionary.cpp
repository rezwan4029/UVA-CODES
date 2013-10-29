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
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64 long long
#define i64U unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({i64 a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795


#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)

int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);

int cs = 1;
//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=1;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//
using namespace std;

string get(int i,int j,char *s)
{
    string str = "";
    for(int k = i ;k<=j ;k++) str += s[k];
    return str;
}

int main()
{
    int T = II ,i,j;

    map<  string , string >Old;
    map<  string , string >New;
    vector<string>ADD,DEL,CHG;

    char OLD[105],NEW[105];
    getchar();
    while(T--)
    {
        Old.clear();
        New.clear();
        ADD.clear();
        DEL.clear();
        CHG.clear();

        gets(OLD); gets(NEW);

        int Oldlen = strlen(OLD);
        int newLen = strlen(NEW);

        int prev1 = 1,prev2;
        string x,y;

        for( i = 2 ; i< Oldlen ;i++)
        {
            if(OLD[i] == ':'){
               x = get(prev1,i-1,OLD);
               prev2 = i+1;
               continue ;
            }
            if(OLD[i] == ',' || OLD[i] == '}'){
               y = get(prev2,i-1,OLD);
               prev1 = i+1;
               Old[x] = y;
               continue ;
            }
        }

        prev1 = 1;

        for( i = 2 ; i< newLen ;i++)
        {
            if(NEW[i] == ':'){
               x = get(prev1,i-1,NEW);
               prev2 = i+1;
               continue ;
            }
            if(NEW[i] == ',' || NEW[i] == '}'){
               y = get(prev2,i-1,NEW);
               prev1 = i+1;
               New[x] = y ;
               continue ;
            }
        }

        map< string , string >::iterator iter,temp;

        for( iter = Old.begin() ; iter != Old.end() ; iter ++ ){

             temp = New.find( iter->first);

             if( temp != New.end() ){
              //  ADD.push_back( iter->first);

                //Old.erase(iter);

                if( iter->second !=  temp->second){
                 CHG.push_back( iter->first);
                }
                New.erase(temp);

             }
             else{
                DEL.push_back(iter->first);
             }

        }
        for(iter = New.begin() ;iter != New.end() ;iter++)ADD.push_back(iter->first);
        vector<string>::iterator it;
        bool f = true;
        if( ADD.size() )
        {
            f = false ;
            all(ADD);
            printf("+");
            for(it = ADD.begin() ;it != ADD.end() ;it++){
                if( it != ADD.begin())printf(",");
                cout<< *it;
            }
             printf("\n");
        }

        if( DEL.size() )
        {
            f = false ;
            all(DEL);
            printf("-");
            for(it = DEL.begin() ;it != DEL.end() ;it++){
                if( it != DEL.begin())printf(",");
                cout<< *it;
            }
              printf("\n");
        }

        if( CHG.size() )
        {
            f = false ;
            all(CHG);
            printf("*");
            for(it = CHG.begin() ;it != CHG.end() ;it++){
                if( it != CHG.begin())printf(",");
                cout<< *it;
            }
            printf("\n");
        }

        if(f) printf("No changes\n");
        //if(T)
        puts("");

    }

    return 0;
}
