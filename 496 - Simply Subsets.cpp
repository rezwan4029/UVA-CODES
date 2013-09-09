#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
#define forstl(i,s) for( __typeof(s.begin())i = s.begin() ; i != s.end() ; i++ )
#define rep(i,s) for( __typeof(s)i = 0 ; i < s ; i++)
#define EQUAL 1
#define DISJOINT 0
#define CONFUSED 2

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

vector<string>token( string a, string b )
{
    const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;
    vector<string>oot; while( *q ) { const char *e = q;while( *e && !count( b.begin(), b.end(),*e ) ) e++;
    oot.push_back( string( q, e ) );q = e; while( count( b.begin(),b.end(), *q ) ) q++;} return oot;
}

vector<int>a,b;

int input()
{
    a.clear();b.clear();
    char s1[5000],s2[5000];
    while(gets(s1))
    {
        gets(s2);
        vector<string>x = token(s1," ");
        vector<string>y = token(s2," ");
        forstl(it,x)a.push_back(toInt(*it));
        forstl(it,y)b.push_back(toInt(*it));
        return 1 ;
    }
    return 0;
}

int isSubset(vector<int>A , vector<int>B)
{
    int sizeA = A.size();
    int sizeB = B.size();
    bool use[sizeA+1] ;
    memset(use,false,sizeof use);
    int cnt = 0 ;
    rep(i,sizeB)
    {
        rep(j,sizeA)
        {
            if(B[i] == A[j] && !use[j] )
            {
                use[j] = true;
                cnt++;
            }
        }
    }
    if( cnt == 0 ) return DISJOINT ;
    return cnt == sizeB ? EQUAL : CONFUSED ;
}
int main()
{
    while(input())
    {
        int szA = a.size();
        int szB = b.size();

        if(szA == szB )
        {
            int res = isSubset(a,b);
            if(res == DISJOINT ) puts("A and B are disjoint");
            else if(res == EQUAL)puts("A equals B");
            else puts("I'm confused!");
        }
        else if( szA > szB )
        {
            int res = isSubset(a,b);
            if(res == DISJOINT ) puts("A and B are disjoint");
            else if( res == EQUAL ) puts("B is a proper subset of A");
            else puts("I'm confused!");
        }
        else
        {
            int res = isSubset(b,a);
            if(res == DISJOINT ) puts("A and B are disjoint");
            else if( res == EQUAL ) puts("A is a proper subset of B");
            else puts("I'm confused!");
        }
    }
}
