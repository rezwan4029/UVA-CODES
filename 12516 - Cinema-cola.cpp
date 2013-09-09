#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
int rows, columns;

int seat[28][102];
int after[28][102];

int conv( string a)
{
    int num = 0;
    if(a.length() == 3 )
    {
            num = (a[2]-'0') + (a[1]-'0')*10;
    }
    else num = a[1] - '0';
    return num;
}
void preSit()
{
    memset(seat,0,sizeof seat);
    memset(after,0,sizeof after);
    int x ; cin >> x ;
    while(x--)
    {
        string a , b ;
        cin >> a >> b ;
        int num = conv(a);

        if(b == "-")
        {
            seat[a[0] - 'A' ][num-1] = 1 ;
        }
        else
        {
            seat[a[0] - 'A' ][num] = 1 ;
        }
       // cout <<  a[0] - 'A' + 1 << " " << num << endl;
    }
}
int main()
{
    while(cin>>rows>>columns)
    {
        if( rows + columns == 0 ) break;

        preSit();
        int q ;
        cin >> q ;
        bool possible = true ;
        while(q--)
        {
            string s ;
            cin >> s ;
            int r = s[0] - 'A'  ;
            int num = conv(s);
            after[r][num] = 1 ;
        }
        rep(i,rows)For(j,columns)
        {
            if(after[i][j] == 1)
            {
                if(seat[i][j-1] == 0 )
                {
                    seat[i][j-1] = 1 ;
                }
                else if(seat[i][j] == 0)
                {
                    seat[i][j] = 1;
                }
                else possible = false;
            }
        }
        printf("%s\n",possible?"YES":"NO");
    }
}
