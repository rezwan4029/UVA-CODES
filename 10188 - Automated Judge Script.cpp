#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
char str[207];
int main(){
    int given , ans , cs =1 ;
    while( scanf("%d",&given) && given){
           getchar();
           string x = "" , y = "" , r1 = "" , r2 = "" ;
           for(int i = 0 ; i < given ; i++ ){
                   gets(str);
                   r1 += str ;
                   int len = strlen(str);
                   for(int j = 0 ; j < len ; j++ ) if( isdigit(str[ j ])) x += str[j];
           } 
           scanf("%d",&ans);
           getchar();
           for(int i = 0 ; i < ans ; i++ ){
                   gets(str);
                   r2 += str;
                   int len = strlen(str);
                   for(int j = 0 ; j < len ; j++ ) if( isdigit(str[ j ])) y += str[j];
           }
           printf("Run #%d: ",cs++);
           if( r1 == r2 && ans == given ) puts("Accepted");
           else if( x == y ) puts("Presentation Error");
           else puts("Wrong Answer");
    }
}
