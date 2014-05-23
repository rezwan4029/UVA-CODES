#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
bool isVowel( char x ){
    return ( x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u' or x == 'y') ;
}
const int MX = 1e6 + 7 ;
char s[MX];
int syllables(string x){
    int len = x.size() ;
    int cnt = 0 ;
    for( int i =  0 ; i < len ; i++ ){
        if( isVowel(x[i]) ){
            while( isVowel(x[i]) and i < len ) i++ ;
            i--;
            cnt++;
        }
    }
    return cnt;
}
int main(){
    while( gets(s) ){
        if( !strcmp(s,"e/o/i") ) return 0 ;
        int len = strlen(s);
        int c = 0 ;
        string A , B , C , X ;
        for( int i = 0 ; i < len ; i++ ){
            if( s[i] == '/' or i == len - 1 ){
                if( i == len - 1 ) X += s[i];
                c++;
                if( c == 1 ) A = X ;
                else if( c == 2 ) B = X ;
                else C = X ;
                X.clear();
            } else {
                X += s[i];
            }
        }
        int p = syllables(A);
        int q = syllables(B);
        int r = syllables(C);
      //  cout << A << "  " << B << "  " << C << endl << endl;
        //cout << p << "  " << q << "  " << r << endl << endl;
        if( p == 5 and q == 7 and r == 5 ) puts("Y");
        else {
            if( p != 5 ) puts("1");
            else if( q != 7 ) puts("2");
            else puts("3");
        }
    }
}
