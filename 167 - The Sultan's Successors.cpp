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
#include <queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

#define INF 1000000007

#define NQ 8

#define X first
#define Y second

int cnt;
vector<int>solution[100];

bool canPlace(int k,int i,int *x){
    rep(j,k) if(i==x[j] || abs(k-j)==abs(i-x[j]) ) return false;
    return true;
}

void Nqueen(int k){
    static int x[NQ];
    rep(i,NQ){
        if(canPlace(k,i,x)){
            x[k]=i;
            if(k==NQ-1){
                cnt++;
                rep(j,NQ) solution[ cnt ].push_back( x[j] );
            }
            else Nqueen(k+1);
        }
    }
}
int board[10][10];

int main()
{
    cnt = 0;
    Nqueen(0);
    int test ;
    scanf("%d",&test);
    while(test--)
    {
        rep(i,8)rep(j,8)scanf("%d",&board[i][j]);

        int ret = 0 ;

        For(solno,cnt)
        {
            int c = 0 ;
            rep(i,8)  c += board[i][ solution[solno][i] ];
            ret = max( c, ret );
        }
        printf("%5d\n",ret);
    }
}
