#include<utility>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

char mat[100][100],s[100];
int row,col,m[100][100];

void input()
{
    col = row = 0;
    while(gets(s) && s[0] )
    {
        if(strlen(s) == 0 )break;
        memcpy(mat[row],s,sizeof s);
        row++;
    }
    col = strlen(mat[0]);
}
void make()
{

    for(int i = 0 ; i < row ; i++ )
            for(int j = 0 ; j < col ; j++ )  m[i][j] = mat[i][j]-'0';
}

pair<int,int>check( int x1 ,int y1 ,int x2 ,int y2)
{
    int val = 0 ;

    for( int i = x1 ; i <= x2 ; i++ )
        for( int j = y1 ; j <= y2 ; j++ ){
            if(m[i][j] == 0 )return pair<int,int>(0,0);
            val++;
    }
    return pair<int,int>(1,val);
}


void p()
{
    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < col ; j++ )
            cout<<m[i][j]<<"    ";
        cout<<endl;
    }
}

int main()
{
    int T;
    scanf("%d",&T); getchar();getchar();
    while(T--)
    {
        input();
        make();
        int ans = 0;
        for(int i = 0 ; i < row ; i++ )
            for( int  j = 0 ; j < col ; j++ )
                for(int k = 0 ; k < row ; k++ )
                    for( int  l = 0 ; l < col ; l++ ){

                        pair<int,int>ret = check(i,j,k,l);

                        if( ret.first == 1 ){
                        ans = max( ans ,ret.second );
                    }
                 //   cout<<ret.first << "   "<<ret.second<<endl;
        }
        printf("%d\n",ans);
        if(T)puts("");
    }
}
