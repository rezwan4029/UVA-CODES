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
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef long long ll;
#define all(X) X.begin() , X.end()
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

struct Info{
    string name , add , dept , Workphone , Homephone , box ,last ;
};
bool cmp(Info a , Info b){
    return a.last < b.last ;
}
Info ans[2000007];
char inp[1000007];
char dpt[1000007];
int main(){
  //  freopen("in.txt", "r", stdin);
    int test = II , pos = 0 ; getchar();

    while(test--){
        gets(dpt);
        string temp , lst ;
        while(gets(inp)){
            int len = strlen(inp);
            if(len == 0 )break;
            ans[pos].dept = dpt ;
            int comma = 0 ;
            temp = "";
            rep(i,len){
                if(inp[i] == ','){
                    comma++;
                    if( comma == 1 || comma == 2){
                        temp += ' ';
                        lst = "";
                    }
                    else if(comma == 3 ){
                        ans[pos].name = temp ;
                        temp = "";
                        ans[pos].last = lst ;
                    }
                    else if(comma == 4 ){
                         ans[pos].add = temp ;
                         temp = "";
                    }
                    else if(comma == 5 ){
                         ans[pos].Homephone = temp ;
                         temp = "";
                    }
                    else if(comma == 6){
                         ans[pos].Workphone = temp ;
                         temp = "";
                    }
                }
                else{
                    temp += inp[i];
                    if(comma == 2 )lst += inp[i];
                }
            }
             ans[pos++].box = temp ;
        }
    }
    sort(ans,ans+pos,cmp);
    rep(i,pos){
        puts("----------------------------------------");
        cout << ans[i].name << endl;
        cout << ans[i].add << endl;
        cout << "Department: " << ans[i].dept << endl;
        cout << "Home Phone: " << ans[i].Homephone << endl;
        cout << "Work Phone: " << ans[i].Workphone << endl;
        cout << "Campus Box: " << ans[i].box << endl;
        //cout << "last : " << ans[i].last << endl;
    }
}
