#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#define inf ~(1<<31)
#define ms(a,x) memset(a,x,sizeof a)
#define sqr(a) ((a)*(a))
using namespace std;
#define rep(i,n) for(__typeof(n) i = 0 ; i < n ; i++)
#define For(i,n) for(__typeof(n) i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin()) i = 0 ; i != n.end() ; i++)
typedef unsigned long long ll;
#define mod 1000000007
#define mx  1000007
#define pi 3.1415926535897932384626433832795


int main()
{
    map<string,int>m;
    for(char i = 'a' ; i <= 'z' ;i++ ) {
        string c = ""; c += i; m[ c ] = i - 'a' + 1 ;
    }
    int x = 27 ;
    for(char i = 'a' ; i <= 'z' ; i++ )
            for( char j = i + 1 ; j <= 'z' ; j++ ) {
        string c = ""; c += i ; c += j ; m[ c ] = x++;
    }
    for(char i = 'a' ; i <= 'z' ; i++ )
        for( char j = i + 1 ; j <= 'z' ; j++ )
            for( char k = j + 1 ; k <= 'z' ; k++ ){
                 string c = ""; c += i ; c += j ; c += k ; m[ c ] = x++;
    }

    for(char i = 'a' ; i <= 'z' ; i++ )
        for( char j = i + 1 ; j <= 'z' ; j++ )
            for( char k = j + 1 ; k <= 'z' ; k++ )
                 for( char l = k + 1 ; l <= 'z' ; l++ ){
                 string c = ""; c += i ; c += j ; c += k ; c += l ; m[ c ] = x++;
    }

    for(char i = 'a' ; i <= 'z' ; i++ )
        for( char j = i + 1 ; j <= 'z' ; j++ )
            for( char k = j + 1 ; k <= 'z' ; k++ )
                 for( char l = k + 1 ; l <= 'z' ; l++ )
                    for( char n = l + 1 ; n <= 'z' ; n++ ){
                 string c = ""; c += i ; c += j ; c += k ; c += l ; c += n ; m[ c ] = x++;
    }


    string s ;

    while(cin >> s )
    {
        cout << m[s] << endl;
    }
}
