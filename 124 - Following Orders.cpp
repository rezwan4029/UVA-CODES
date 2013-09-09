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

#define mod   100000007

char inp[1007];
char item[1007];
int n;
bool g[1007][1007];
vector<char>res;
map<string,bool>done;
bool took[1007];

vector<char>conv(char *s){
    vector<char>x;
    int len = strlen(s);
    rep(i,len){
        if(isspace(s[i]))continue;
        x.pb(s[i]);
    }
    return x;
}

bool isvalid(char x){
    forstl(it,res){
        if( g[ (*it) - 'a' ][x - 'a' ]  == true) return false;
    }
    return true;
}
void back()
{
    if(res.size() == n ){
        string x ="";
        forstl(it,res)x += *it;
        if(done[x] == false){
            done[x] = true;
            cout<< x << endl;
        }
        return;
    }
    rep(i,n)
    {
        if(took[i] == false && isvalid(item[i])  ){
            took[i] = true;
            res.pb(item[i]);
            back();
            took[i] = false;
            res.pop_back();
        }
    }
}
int main()
{
  bool f = false;
  while(gets(inp))
  {
     n = 0 ;
     rep(i,strlen(inp))if(isalpha(inp[i])) item[n++] = inp[i];
    // cout << n << endl;
    //rep(i,n) cout << item[i] << "    ";
     gets(inp);
     ms(took,false);
     ms(g,false);
     done.clear();
     res.clear();
     sort(item,item+n);
     vector<char>x = conv(inp);
     for(int i = 0 ; i < x.size() ; i += 2 ){
            g[ x[i+1] - 'a' ][  x[i] - 'a'  ] = true;
           // cout << x[i] << " .... " << x[i+1] <<endl;
     }
     if(f)puts(""); f = 1 ;
     back();
  }
}
