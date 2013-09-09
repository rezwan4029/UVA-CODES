#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#define inf ~(1<<31)
#define ms(a,x) memset(a,x,sizeof a)
#define sqr(a) ((a)*(a))
using namespace std;
#define rep(i,n) for(__typeof(n) i = 0 ; i < n ; i++)
#define For(i,n) for(__typeof(n) i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin()) i = 0 ; i != n.end() ; i++)
typedef long long ll;

char mat[12][12];


int main()
{
    int n , test ;

    cin >> test ;

    For(cs,test)
    {
        cin >> n ;

        rep(i,n) scanf("%s",mat[i]);

        printf("Case %d:\n",cs);

        rep(i,n)
        {
            rep(j,n)
            {
                if(mat[i][j]=='.')
                {
                    rep(k,26)
                    {
                        int x = k + 65 ;

                        if(mat[i][j-1] != x && mat[i-1][j] != x && mat[i][j+1] != x && mat[i+1][j] != x )
                        {
                            mat[i][j] = x ;
                            break;
                        }
                    }
                }
                cout << mat[i][j];
            }
            cout << endl;
        }



    }
}
