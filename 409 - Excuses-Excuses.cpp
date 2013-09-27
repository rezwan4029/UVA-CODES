/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

struct myStr{
    string Str ;
    int Cnt;
    myStr(string _s , int _c){
        Str = _s , Cnt = _c ;
    }
    myStr(){}
};

vector<string>Split(string s ){
    vector<string>ret;
    int len = s.size() ;
    string now = "";
    rep(i,len){
        if( isupper(s[i]) ) s[i] = tolower(s[i]);
        if( islower(s[i])  ){
            now += s[i];
        }
        else{
            if(now.size()){
                ret.pb(now);
                now = "";
            }
            now = "";
        }
    }
    if(now.size()){
        ret.pb(now);
        now = "";
    }
    return ret ;
}

int main(){
    int nCs = 1 ;
    int nExcuses , nLines ;
    while(scanf("%d %d",&nExcuses,&nLines)==2){
        map<string,bool>Hash;
        rep(i,nExcuses){
            string Str ;
            cin >> Str ;
            Hash[Str] = true ;
        }
        vector< myStr > E ;
        getchar();
        int mxCnt = 0 ;
        rep(i,nLines){
            string Str ;
            getline(cin,Str);
            vector<string>geT = Split(Str);
            int Cnt = 0 ;
            forstl(it,geT) if(Hash[*it] == true ) Cnt++ ;
            E.pb( myStr(Str,Cnt) ) ;
            //cout << "--->> "<< Str << "  "<< Cnt << endl;
            mxCnt = max( mxCnt , Cnt );
        }
        int sz = E.size() ;
        printf("Excuse Set #%d\n",nCs++);
        rep(i,sz){
            if( E[i].Cnt == mxCnt ) cout << E[i].Str << endl ;
        }
        puts("");
    }
}
