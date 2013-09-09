#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

int f(char m)
{
    int n = m;
    int s = 0;
    while(n){
        int x = n&1;
        if(x) s += 500;
        else  s += 250;
        n >>=1;
    }
    return s;
}
int main()
{
  char c[30][30];
  int t,i,j,cs=1;
  string Ls ,Rs;
  scanf("%d",&t);
  while(t--)
  {
      for( i = 0 ; i < 8 ; i++)scanf("%s",c[i]);

      int lft = 0 , ryt = 0;
      int downlft , downryt;
      Rs = Ls = "";
      for( i = 1 ; i < 8 ; i++)
        for( j = 1 ; j < 8 ; j++){
            if(isupper(c[i][j])) lft += f( c[i][j] ) , Ls += c[i][j];
            else if(c[i][j] == '_'){
                downlft = i;
            break;
            }
        }

      for( i = 1 ; i < 8 ; i++)
        for( j = 10 ; j < 18 ; j++){
            if(isupper(c[i][j])) ryt += f( c[i][j] ) , Rs += c[i][j];
             else if(c[i][j] == '_'){
                downryt = i;
            break;
            }
        }
        printf("Case %d:\n",cs++);
    //  cout<<"\n\n "<<lft <<"          " << ryt << endl;
      if(    lft > ryt && downlft > downryt
          || lft < ryt && downlft < downryt
          || lft == ryt && downlft == downryt
        )
            puts("The figure is correct.");
        else {

            for( i = Ls.length() ; i < 6 ; i++)Ls+=".";
            for( i = Rs.length() ; i < 6 ; i++)Rs+=".";

           // cout<<"\n\n "<<Ls<<"     "<<Rs<<endl<<endl;

          if(lft > ryt)
          {
            puts("........||.../\\...");
            puts("........||../..\\..");
            puts(".../\\...||./....\\.");
            printf("../..\\..||/");
            cout<<Rs<<"\\"<<endl;
            puts("./....\\.||\\______/");
            cout<<"/"<<Ls<<"\\||........"<<endl;
            puts("\\______/||........");


          }
          else if( lft < ryt)
          {
            puts(".../\\...||........");
            puts("../..\\..||........");
            puts("./....\\.||.../\\...");
            cout<<"/"<<Ls<<"\\||../..\\.."<<endl;
            puts("\\______/||./....\\.");
            cout<<"........||/"<<Rs<<"\\"<<endl;
            puts("........||\\______/");

          }
          else
          {
            puts("........||........");
            puts(".../\\...||.../\\...");
            puts("../..\\..||../..\\..");
            puts("./....\\.||./....\\.");
           // printf(".%s\||/%s\\",Ls,Rs);
            cout<<"/"<<Ls<<"\\||/"<<Rs<<"\\"<<endl;
            puts("\\______/||\\______/");
            puts("........||........");

          }

        }
  }
}
/*

........||.../\...
........||../..\..
.../\...||./....\.
../..\..||/G.....\
./....\.||\______/
/YQYFU.\||........
\______/||........
------------------

*/

/*


*/

/*
col = 0 - 7 last a hbe shob --ase 18 ta
0 - 7 first half
second 10 - 17 porjonto


*/
