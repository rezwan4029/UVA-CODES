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
#include<cctype>
#include<sstream>
#include<set>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define INF 2147483647

struct football{
    string name;
    int attack , defend ;
}F[12];

bool cmp(football a , football b){
        if(a.attack > b.attack )return true;
        if(a.attack == b.attack && a.defend < b.defend) return true ;
        if(a.attack == b.attack && a.defend == b.defend && a.name < b.name ) return true ;
        return false;
}
bool nm(football a , football b){
    return a.name < b.name ;
}
int main()
{
    int T , cs = 1; scanf("%d",&T);

    while(T--)
    {
        rep(i,10) cin >> F[i].name >> F[i].attack >> F[i].defend ;
        sort(F,F+10,cmp);
        sort(F,F+5,nm);
        sort(F+5,F+10,nm);
        printf("Case %d:\n",cs++);
        cout << "(";
        rep(i,5) {
            cout << F[i].name ;
            if(i == 4 ) cout << ")\n";
            else cout << ", ";
        }
        cout << "(";
        for( int i = 5 ; i < 10 ; i++ ){
             cout << F[i].name ;
             if(i == 9 ) cout << ")\n";
             else cout << ", ";
        }
    }
}
