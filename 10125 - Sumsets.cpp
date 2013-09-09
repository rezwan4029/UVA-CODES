/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

int x[1007];

int main()
{
    int a , b , c , d , n ;

    while(scanf("%d",&n) && n )
    {

        rep(i,n) scanf("%d",x+i);

        sort(x,x+n);
        bool F = true ;

        for(int i = n - 1 ; i >= 0  && F ; i-- ){
            for(int j = 0 ; j < n && F  ; j++ ){ if(i == j )continue ;
                for( int k = j + 1 ; k < n && F ; k++ ){ if(i == k )continue ;
                    for(int l = k + 1 ; l < n && F ; l++ ){ if(i == l ) continue ;
                        if(x[i] == x[j]+x[k]+x[l] ) printf("%d\n",x[i]) , F = false ;
                    }
                }
            }
        }
        if(F)puts("no solution");
    }
}
