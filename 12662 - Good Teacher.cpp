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

ll  Pow(ll  B,ll  P)
{
    ll  R=1;    //compute b^p
    while(P>0)
    {
        if(P&1) R=(R*B);
        P/=2;
        B=(B*B);
    }
    return R;
}
bool isVowel(char s)
{
    s=tolower(s);
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')return true;
    return false;
}
ll  GCD(ll  a,ll  b)
{
    while(b)
    {
        b ^= a ^=b ^= a %=b;
    }
    return a;
}
ll  LCM(ll  a,ll  b)
{
    return (a / GCD(a,b)*b);
}
ll  BigMod(ll  B,ll  P,ll  M)
{
    ll  R=1;    //compute b^p%m
    while(P>0)
    {
        if(P&1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (ll )R;
}
string i2b(ll a)
{
    string s ;
    do
    {
        s += (a&1) + '0' ,  a >>= 1;
    }
    while(a);
    reverse(all(s));
    return s;
}
ll toInt(string s)
{
    ll r = 0 ;
    istringstream sin(s);
    sin>>r;
    return r;
}
string toString(ll number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}


vector<string>Split(string s )
{
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen ("in.txt", "r", stdin);
#endif
    int n   ;
    while( scanf("%d",&n) == 1 ){
    string s ;
    getchar();
    getline(cin,s);

    vector<string>now = Split(s);

    //forstl(it,now) cout << *it << endl;
    int m = II , sz = now.size();
    while(m--)
    {
        int pos = II - 1 ;
        string who = now[pos];
        if(who == "?" )
        {

            int c1 = 1 , c2 =  1;
            while( pos+c1 < sz && now[pos+c1] == "?" ) c1++;
            while( pos-c2 >= 0 && now[pos-c2] == "?")c2++;
            if(pos+c1 == sz )
            {
                rep(i,c2)
                {
                    cout << "right of ";
                }
                cout << now[pos-c2] << endl;

            }
            else if(pos-c2 == -1 )
            {
                rep(i,c1)
                {
                    cout << "left of ";
                }
                cout << now[pos+c1] << endl;
            }
            else if(c1 > c2 )
            {
                rep(i,c2)
                {
                    cout << "right of ";
                }
                cout << now[pos-c2] << endl;

            }
            else if( c1 < c2 )
            {
                rep(i,c1)
                {
                    cout << "left of ";
                }
                cout << now[pos+c1] << endl;

            }
            else
            {
                cout << "middle of " << now[pos-c2] << " and " << now[pos+c1] << endl;

             }
        }
             else
        {
            cout << who << endl;
        }
      }
    }
}
