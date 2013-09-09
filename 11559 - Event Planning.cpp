#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )

int main()
{
    int nPeople , Budget , nHotel , Weekends ;
    while( cin >> nPeople >> Budget >> nHotel >> Weekends)
    {
           int minCost = 9999999 ;
           
           int percost ;
           
           rep( i , nHotel)
           {
                cin >> percost ;
                int cnt = 0 ;
                rep(j,Weekends) 
                {
                   int beds ;
                   cin >>beds;
                   if(beds>=nPeople){
                              int totCost = nPeople * percost ; 
                              minCost = min( totCost , minCost);  
                   }   
                }

           }
           if( minCost > Budget) puts("stay home");
           else cout << minCost << endl;
    }  
}
