#include <cctype>
#include <stdio.h>
#include <utility>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define sz 1005

char recipe[sz],title[sz],item[sz];

vector< pair<string,int> >ans;

map<string,int>ingredents;

bool cmp(pair<string,int> x , pair<string,int> y){
    if(x.second == y.second ) return x.first < y.first;
    return ( x.second < y.second );
}
int main()
{
    int binders , n , m , b ,freq;
    cin >> binders ;

    while(binders--)
    {
        getchar();

        ingredents.clear() ; ans.clear();

        gets(title);

        for(int i = 0 ; title[i] ; i++ ) cout << char(toupper(title[i]));
        cout << endl;

        cin >> m >> n >> b ;

        for(int i = 0 ; i < m ; i++ ) {
            cin >> item >> freq ;
            ingredents[item] = freq;
        }



        for( int i = 0 ; i < n ; i++ )
        {
            getchar();
            gets(recipe);

            int need , total_cost = 0 ; cin >> need ;
            while(need--){
                cin >> item >> freq ;
                total_cost += ingredents[  item ] * freq ;
            }
            if( total_cost <= b ) ans.push_back(make_pair(recipe,total_cost));
           
        }


//    cout << "size --- >  " << ans.size() << endl;
    if(ans.size()==0) puts("Too expensive!");
    else{
        sort(ans.begin(),ans.end(),cmp);
        for(int i = 0 ; i < ans.size() ; i++ ) cout << ans[i].first << endl;
    }
    puts("");
    }
}
