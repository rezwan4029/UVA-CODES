#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


#define MAXN  100002
#define MAXL 20

int n ,stp,mv,suffix[MAXN],tmp[MAXN];
int sum[MAXN],cnt[MAXN],rank[MAXL][MAXN];
int lcp[MAXN];
char str[MAXN];

int LCP(int u,int v){
    int ret=0,i;
    for(i = stp; i >= 0; i--){
                if(rank[i][u]==rank[i][v]){
                        ret += 1<<i;
                        u += 1<<i;
                        v += 1<<i;
                }
        }
        return ret;
}
bool equal(int u,int v){
        if(!stp)return str[u]==str[v];
        if(rank[stp-1][u]!=rank[stp-1][v]) return false;
        int a = u + mv < n ? rank[stp-1][u+mv] : -1;
        int b = v + mv < n ? rank[stp-1][v+mv] : -1;
        return a == b ;
}
void update(){
        int i;
        for(i = 0;i < n; i ++) sum[ i ] = 0;

        int rnk = 0;
        for(i = 0;i < n;i++){
                suffix[ i ] = tmp[ i ];
                if( i&&!equal(suffix[i],suffix[i-1])){
                        rank[stp][suffix[i]]=++rnk;
                        sum[rnk+1]=sum[rnk];
                }
                else rank[stp][suffix[i]]=rnk;
                sum[rnk+1]++;
        }
}
void Sort(){
        int i;
        for(i = 0; i < n; i ++ ) cnt[ i ] = 0;
        memset(tmp,-1,sizeof tmp);
        for(i = 0 ; i < mv; i ++){
                int idx = rank[ stp - 1 ][ n-i-1 ];
                int x = sum[ idx ];
                tmp[ x + cnt[ idx ] ] = n-i-1;
                cnt[ idx ]++;
        }
        for(i = 0;i < n; i ++ ){
                int idx = suffix[ i ] - mv;
                if(idx<0)continue;
                idx = rank[stp-1][idx];
                int x = sum[ idx ];
                tmp[ x + cnt[ idx ] ] = suffix[ i ] - mv;
                cnt[idx]++;
        }
        update();
        return;
}
bool cmp(const int &a,const int &b){
        if(str[a]!=str[b]) return str[a]<str[b];
        return false;
}
int main(){
        while(true){

        scanf ( "%s", str  );
        if(str[0]=='*') break ;
        n = strlen(str);
        int i;
        for(i = 0;i < n;i++) tmp[ i ] = i ;

        sort(tmp,tmp+n,cmp);
        stp = 0;
        update();
        ++stp;
        for( mv = 1; mv < n;  mv <<= 1){
                Sort();
                stp++;
        }
        stp--;
        for(i = 0;i<=stp; i++)  rank[ i ][ n ] = -1;
        int res=0;
        for(i = 1; i < n; i ++)
                lcp[i] = LCP(suffix[i],suffix[i-1]);
        for(i = 1 ; i < n ;i++)
        {
            int x = lcp[i] - lcp[i-1];
            if(x > 0 )res+=x;
        }
        printf("%d\n",res);
        }
        return 0;
}
