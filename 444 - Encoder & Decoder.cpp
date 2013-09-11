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

#define FOR(i,n)  for(int i=1;i<=n;i++)
#define FORa(i,n) for(int i=0;i<n;i++)
#define LL long long
#define MAX 99999999
#define MIN -99999999
#define EPS 1e-9
using namespace std;


int main(){
    char msg[1005];
    int i, n, len;
        while (gets(msg))
        {
        len =strlen(msg);
        reverse(msg, msg+len);

        n = 0;
        if ( (msg[0] -48) >= 0 && msg[0]-48 <= 9){
            for (i = 0; msg[i]; i++){
                n = n * 10 + msg[i]-48; // this loop will continue if n doesn't  enters in if condition :)
                if ( (n >= 65 && n <= 90) || (n >= 97 && n <= 122) || n == 32 || n == 33
                    ||n == 44 || n == 46 || n == 58 || n == 59 || n == 63){
                    cout << (char) n;
                    n = 0;
                }
            }
        }
        else{
            for (i = 0; msg[i];i++){
                n = msg[i];
                while (n){
                    cout << n % 10;
                    n = n / 10;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
