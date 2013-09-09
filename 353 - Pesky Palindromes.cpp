#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

#define REP(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define FOR(i,n) for( __typeof(n)i = 1 ; i <= n ; i++ )
#define forstl(i,n) for( __typeof(n.begin())i = n.begin() ; i != n.end() ; i++ )

using namespace std;

char s[90];
map<string,bool> v;

int solve(int i,int j)
{
    char t1[90];
    int x = 0;
    REP(k,j) t1[x++]=s[i++];
    t1[x]=0;
    string t2 = t1;
    reverse(t2.begin(),t2.end());
   // cout<< t1 << "   "<< t2<<endl;
    if(v[t1]) return 0;
    v[t1]=true;
    return t1 == t2 ;
}

int main()
{
        while(cin>>s)
        {
            v.clear();
            int len = strlen(s);
            int ret = 0;
            REP(i,len)REP(j,len) ret += solve(i,len-j);
            printf("The string '%s' contains %d palindromes.\n",s,ret);
        }
}
