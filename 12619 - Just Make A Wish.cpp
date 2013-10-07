

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>

#define i64 long long
#define pb push_back


int cs = 1;



using namespace std;

#define sz 1000007

i64  BigMod(i64  B,i64  P,i64  M){ i64  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (i64 )R;} //compute b^p%m

struct store{
    int p ,c ;
}temp;

vector<store>arr[sz];

map<i64,i64>m,tmp;
bool flag[sz];


void Gen()
{
    for(int i = 2 ; i <= sz - 7 ; i++ ){
            if(flag[i] == false){

                temp.p = i ;
                temp.c = 1 ;
                arr[i].pb(temp);
                for(int j = 2 * i ; j <= sz - 7 ; j += i ){
                    flag[j] = true;
                    int t = j ;
                    temp.p = i ;
                    temp.c = 0 ;
                    while(t % i == 0 ){
                        t /= i ;
                        temp.c++;
                    }
                    arr[j].pb(temp);
                }
            }
    }
    int tot = 0 ;
    for(int i = 2 ; i <= sz - 7 ; i++ ){
        if(flag[i] == 0) m[i] = tot++;
    }
}

#define mod 1000000007


i64 modinv(i64 B){
    return BigMod(B,mod-2,mod);
}
int main()
{
    Gen();
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        int d , x ;
        scanf("%d",&d);
        tmp.clear();
        i64 ans = 0 , cnt = 1 ;
        while(d--)
        {
            scanf("%d",&x);

            if(x > 0 )
            {
                for(int i = 0 ; i < arr[x].size() ; i++ ){

                        cnt *= modinv(tmp[ m[ arr[x][i].p ] ] + 1) ;
                        cnt = (cnt + mod) %mod;
                        tmp[ m[ arr[x][i].p ] ] += arr[x][i].c;
                        cnt *= ( tmp[ m[ arr[x][i].p ] ]+1 ) ;
                        cnt = (cnt + mod) %mod;
                }
            }
            else
            {
                x = -x ;

                for(int i = 0 ; i < arr[x].size() ; i++ ){

                        cnt *= modinv(tmp[ m[ arr[x][i].p ] ] + 1) ;
                        cnt = (cnt + mod) %mod;
                        tmp[ m[ arr[x][i].p ] ] -= arr[x][i].c;
                        cnt *= ( tmp[ m[ arr[x][i].p ] ]+1 ) ;
                        cnt = (cnt + mod) %mod;
                }
            }
            ans = (ans + cnt )% mod ;
        }
        printf("Case %d: %lld\n",cs++,ans);
    }
}
/*
1
5
12
3
-2
5
-6
**/
