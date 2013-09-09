#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long i64;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

#define sz 300005

string w ;
int n ;
char str[sz];
const int mod  = 20071027 ;

struct node{
        int val;
        node *next[28];
        node(){
                val=0;
                for(int i=0;i<28;i++)
                        next[i]=NULL;
        }
};

node *root=new node();

void insert(char *str){

        node *curr=root;

        for(int i=0;str[i];i++){

                if(curr->next[ str[i]-'a' ]==NULL){
                        curr->next[ str[i] - 'a' ]=new node();
                }

                curr=curr->next[ str[i] - 'a' ];
        }
        curr->val++;
}

int dp[sz];

int solve(int len)
{
    if(len == w.size()) return 1;

    int &ret = dp[len];
    if(ret != -1 ) return ret;

    ret = 0 ;

    node *curr=root;

    int now_len = len ;

    while(true)
    {
        if(now_len >= w.size())break;

        curr=curr->next[ w[ now_len ] - 'a' ];

        if(curr == NULL )break;

        if( curr->val ) ret = ( ret + solve(now_len+1) ) % mod;

        now_len++;
    }

    return ret % mod ;
}


int main()
{
        int cs = 1 ;

        while(cin >> w){
            scanf("%d",&n);
            root = new node();
            rep(i,n) {
                cin >> str ;
                insert(str) ;
            }
            memset(dp,-1,sizeof dp);
            int ret = solve(0);
            printf("Case %d: %d\n",cs++ , ret);
        }
}
