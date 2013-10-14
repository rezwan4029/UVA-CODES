/*
    Royal_Flush , AUST
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
typedef long long ll;
typedef vector<int> vi ;
typedef vector<ll>vl;

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
bool isVowel(char s){s=tolower(s); if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')return true;return false;}
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m
string i2b(ll a) {string s ;do { s += (a&1) + '0' ,  a >>= 1; }while(a);reverse(all(s));return s;}
ll toInt(string s){ll r = 0 ;istringstream sin(s); sin>>r;return r;}
string toString(ll number){stringstream ss; ss << number;return ss.str();}

int N , SRC , DST , M ;

struct Node{
    int u , open , close , time ;
    Node(int _u ,int _o, int _c , int _t ){
        u = _u;
        open = _o;
        close = _c ;
        time = _t;
    }
    Node(){}

};

vector<Node>adj[50007];

int d[305];
//bool Vis[305];

void Reset(){
    rep(i,N+1) {
        adj[i].clear();
        //Vis[i] = false ;
        d[i] = -1;
    }
}

struct race{
    int node , cost ;
    race(int _n , int _c ){
        node = _n , cost = _c ;
    }
    race(){}
    bool operator <(const race& A)const{
        return cost > A.cost;
    }
};

void Dijstra(){
    priority_queue< race >Q;
    d[SRC] = 0 ;
    Q.push( race(SRC,0) );
    while(!Q.empty()){

        race now = Q.top(); Q.pop();

        int currNode = now.node , currCost = now.cost ;

/*
        if(Vis[currNode])continue;
        Vis[currNode] = true ;
*/
        forstl( it , adj[currNode] )
        {
                //cout << "SZ = " << Q.size() << endl;
                int nxtNode = it->u ;
                int open = it->open ;
                int close = it->close ;
                int time = it->time ;

                //cout << "node = " << nxtNode << "   open -> " << open << "   closes -> " << close << "   cost = " << time << endl;
                if( time > open ) continue;

                int rem = currCost % (open+close);

                //cout << "curr :: " << currCost << " REM :: " << rem<<endl;

                if(rem >= open)
                {
                    rem -= open;
                    //close = close - rem ;
                    rem = close - rem ;
                    if( d[nxtNode] == -1 || rem+time+currCost < d[nxtNode] ){
                        d[nxtNode] = rem+time+currCost;
                        Q.push(race(nxtNode,rem+time+currCost));
                    }
                }

                else
                {
                    int tmp = open - rem  ;

                    if(tmp >= time)
                    {
                        //cout << "IF :: ";
                        //cout << tmp << " " << close << " " << time << " " << currCost+time << endl;
                        if(d[nxtNode] == -1 || currCost+time < d[nxtNode]){
                            d[nxtNode] = currCost+time;
                            Q.push(race(nxtNode,currCost+time));
                        }
                    }
                    else
                    {
                        //cout << "Else :: ";
                        //cout << tmp << " " << close << " " << time << " " << tmp+close+time << endl;
                        if(d[nxtNode] == -1 || currCost+tmp+close+time < d[nxtNode]){
                            d[nxtNode] = currCost+tmp+close+time;
                            Q.push(race(nxtNode,currCost+tmp+close+time));
                        }
                    }
                }
        }
        //cout << "SZ = " << Q.size() << endl;
    }
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1 ;
    while( cin >> N >> M >> SRC >> DST )
    {
        Reset();
        rep(i,M){
            int u = II , v = II , o = II , c = II , t = II ;
            adj[u].pb(  Node(v,o,c,t) );
        }
        Dijstra();
        printf("Case %d: %d\n",cs++,d[DST]);
    }
}
