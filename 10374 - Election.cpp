/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-9
#define INF 1<<30
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

map<string,string>party;
map<string,int>Cnt;

int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif
    int t = II ; bool flag = true ;
    while(t--)
    {
        int n = II ;
        while(getchar()!='\n');
        if(!flag) cout<<endl; flag = false ;
        party.clear() , Cnt.clear() ;
        rep(i,n){
            string s1 , s2  ;
            getline(cin,s1);
            getline(cin,s2);
            party[s1] = s2 ;
        }
        int m = II ;
        int mx = 0 ;
        string MM ;
        while(getchar()!='\n');
        rep(i,m){
            string s1 ;
            getline(cin,s1);
            Cnt[s1]++;
            if( Cnt[s1] > mx ){
                mx  = Cnt[s1];
                MM = s1 ;
            }
        }
        int tmp = 0 ;
        forstl(it,Cnt) tmp += ( it->second == mx ) ;
        if( tmp == 1 ){
                cout << party[ MM ]<< endl;
        }
        else{
            printf("tie\n");
        }
    }
}
