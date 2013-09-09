/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with(0);cin.tie(0);
#define pb push_back
#define all(x) (x.begin(),x.end() )
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

int SZ(int number){ stringstream ss;ss << number; string s =  ss.str(); return s.size();}
int main(){
   // freopen("in.txt", "r", stdin);
    int n , cs = 1;
    while(scanf("%d",&n) && n ){
        int x , sum = 0 , tot , a , b , lenA ,lenB ,lenC , mxLen , dash ;
        rep(i,n){
            x = II ;
            sum += x ;
        }
        bool sign = sum >= 0 ? false : true ;
        sum >= 0 ? sum : sum *= -1 ;
        printf("Case %d:\n",cs++);
        if(sum % n == 0 ) {
            int r = sum / n ;
            if(!sign) printf("%d\n",r);
            else printf("- %d\n",r);
            continue;
        }
        int g = __gcd(sum,n);
        sum /= g , n /= g ;
       // cout << sign << "   "<< sum << "  "<< n << endl;
        if(sum == 1 ){
            lenA = SZ(sum) , lenB = SZ(n);
            mxLen = max(lenA,lenB);
            dash = mxLen - lenA ;
            rep(i,dash)printf(" ");
            if(sign)printf("  ");
            printf("%d\n",sum);
            if(sign)printf("- "); rep(i,mxLen)printf("-");puts("");
            dash = mxLen - lenB ;
            rep(i,dash)printf(" ");
            if(sign)printf("  ");
            printf("%d\n",n);
            continue ;
        }
        a = sum / n ;
        int c = n ;
        b = sum - a * c ;
        //cout << a << "  " << b << "  " << c << endl;
        lenA = SZ(a) , lenB = SZ(b) , lenC = SZ(c) ;
        mxLen = max(lenC,lenB);
        dash = lenA + mxLen - lenB ;
        rep(i,dash)printf(" ");
        if(sign)printf("  ");
        printf("%d\n",b);
        if(sign)printf("- ");
        printf("%d",a);
        rep(i,mxLen)printf("-");
        printf("\n");
        dash = lenA + mxLen - lenC ;
        rep(i,dash)printf(" ");
        if(sign)printf("  ");
        printf("%d\n",c);
    }
}
