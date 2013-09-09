#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#define inf 9999999
#define ms(a,x) memset(a,x,sizeof a)
#define sqr(a) ((a)*(a))
using namespace std;
#define rep(i,n) for(__typeof(n) i = 0 ; i < n ; i++)
#define For(i,n) for(__typeof(n) i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin()) i = n.begin() ; i != n.end() ; i++)
typedef long long ll;
#define mod 1000000007
#define mx  1000007
#define pi 3.1415926535897932384626433832795

#define psi pair<string,int>
int par[mx];

int find(int p){
    if( p == par[p] ) return p;
    return find(par[p]);
}
void Union(int a,int b){
    par[find(a)] = find(b);
}
bool isUnion(int x ,int y){
    if(find(par[x]) == find(par[y])) return true;
    return false;
}

int main()
{
    int n , x, y;
    while( cin >> x ){
        For(i,mx-7) par[i] = i;
        int ans = 0 ;
        while(cin >> y){
            if(isUnion(x,y)) ans++;
            else Union(x,y);
            cin >> x ;
            if(x == -1 ) break ;
        } cout << ans << endl ;
    }
}
