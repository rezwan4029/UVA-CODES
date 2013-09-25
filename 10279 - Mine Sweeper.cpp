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

int main()
{
    char bombs[10][10];
    char Cnt[10][10];
    int n , Ans[12][12];
    int test = II ;
    while(test--)
    {
        cin >> n ;
        rep(i,n) rep(j,n) cin >> bombs[i][j];

        bool ok = true;
        rep(i,n)
        {
            rep(j,n)
            {
                cin >> Cnt[i][j];
                if ( Cnt[i][j] == 'x' && bombs[i][j] == '*') ok = false;
            }
        }

        ms(Ans,0);

        rep(i,n)
        {
            rep(j,n)
            {
                if (bombs[i][j] == '.') continue;
                Ans[i][j+1]++;
                Ans[i+2][j+1]++;
                Ans[i+1][j]++;
                Ans[i+1][j+2]++;
                Ans[i][j]++;
                Ans[i+2][j]++;
                Ans[i][j+2]++;
                Ans[i+2][j+2]++;
            }
        }

        rep(i,n)
        {
            rep(j,n)
            {
                if (!ok && bombs[i][j] == '*')
                {
                    cout << '*';
                    continue;
                }
                if (Cnt[i][j] == 'x')
                {
                    cout << Ans[i+1][j+1];
                }
                else
                {
                    cout << '.';
                }
            }
            cout << endl;
        }
        if( test ) cout << endl;
    }
    return 0;
}
