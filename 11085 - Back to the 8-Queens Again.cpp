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


int cnt = 0 ;
int sol[95][10];

bool canPlace(int k,int i,int *x){
    rep(j,k) if(i==x[j] || abs(k-j)==abs(i-x[j])) return false;
    return true;
}

void Nqueen(int k){
    static int x[NQ];
    rep(i,NQ){
        if(canPlace(k,i,x)){
            x[k]=i;
            if(k==NQ-1){
                cnt++;
                rep(j,NQ) sol[cnt][j] = x[j];
            }
            else Nqueen(k+1);
        }
    }
}
int X[10];
int main()
{
    Nqueen(0);
    int T , cs = 1 ;
    //scanf("%d",&T);
    while(cin >> X[0]){
        For(i,7) cin >> X[i] ;
        int ans = 8 ;
        For(i,cnt)
        {
            int r = 0 ;
            rep(j,NQ) if( X[j]-1 != sol[i][j] ) r++;
            ans = min( ans , r );
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
