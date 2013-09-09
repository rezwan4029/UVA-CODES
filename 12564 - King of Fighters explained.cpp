#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

int r1[2][104][104],r2[2][104][104];

int main()
{
        int t,cs=1;
        scanf("%d",&t);
        while(t--)
        {
            memset(r1,0,sizeof r1);
            memset(r2,0,sizeof r2);
            int a ,b;
            scanf("%d %d",&a,&b);
            while(a--)
            {
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                for( int i = y1 ; i <y2 ;i++  )
                    for( int j = x1 ;j < x2 ; j++ )
                        r1[0][i][j] = 1; // 0 means attacking
            }
            while(b--)
            {
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                for( int i = y1 ; i <y2 ;i++  )
                    for( int j = x1 ;j < x2 ; j++ )
                        r1[1][i][j] = 1; // 1 means weak
            }

            scanf("%d %d",&a,&b);
            while(a--)
            {
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                for( int i = y1 ; i <y2 ;i++  )
                    for( int j = x1 ;j < x2 ; j++ )
                        r2[0][i][j] = 1;
            }
            while(b--)
            {
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                for( int i = y1 ; i <y2 ;i++  )
                    for( int j = x1 ;j < x2 ; j++ )
                        r2[1][i][j] = 1;
            }

            bool F = false ,S = false;

            for(int  i = 0 ; i <= 100 ; i++)
                for( int j = 0 ; j <= 100 ; j++ )
            {
                if( r1[0][i][j] == r2[1][i][j] && r2[1][i][j] == 1)  F = true;
                if( r1[1][i][j] == r2[0][i][j] && r2[0][i][j] == 1 ) S = true;
            }
            printf("Case %d: ",cs++);
            if( F && S)puts("Both");
            else if( !F && S)puts("First");
            else if( F && !S)puts("Second");
            else    puts("Neither");
        }
}
