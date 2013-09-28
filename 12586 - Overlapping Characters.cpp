/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<30
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanPlacef("%d", &a); a;})
#define LL  ({ll  a; scanPlacef("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef  long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )


int Mp[20][50];
char grid[128][20][50];
char Str[100];
bool canPlace[128];

void draw( int pos ) {
	rep(i,16)
		rep(j,43)
			if( grid[pos][i][j] == '*' )
                Mp[i][j] = Mp[i][j] == 0 ? pos : -1;
}

int main(){
    //freopen("in.txt", "r", stdin);
	int n, Q , cs = 1;
	scanf("%d %d", &n, &Q );
	scanf("%s",Str);
	rep(i,n) rep(j,17) scanf("%s",grid[ Str[i] ][j]);
	while(Q--){
		scanf("%s",Str);
		ms(Mp,0);
		int len = strlen(Str);
        rep(i,len) draw( Str[i] );
		ms( canPlace, 0 );
		rep(i,16)
            rep(j,43)
				if( Mp[i][j] != -1 )
					canPlace[ Mp[i][j] ] = true;
		printf("Query %d: ",cs++);
		rep(i,len) printf("%c",canPlace[ Str[i] ] ? 'Y' : 'N' );
		puts("");
	}
}
