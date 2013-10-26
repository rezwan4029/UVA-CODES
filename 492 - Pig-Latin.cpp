/*
    Royal Flush , AUST
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef vector<int> vi;
typedef set<int> si;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

bool isVowel(char s){
    s = tolower(s);
    return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ) ;
}

int main() {
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    string Str ;
	while (getline(cin, Str)){
		string word ;
		int len = Str.size() ;
		rep(i,len){
			if (isalpha(Str[i])) word += Str[i];
			else{
				if (!word.empty()){
					if (!isVowel(word[0])){
						word.push_back( word[0] );
						word.erase(0,1);
					}
					cout << word << "ay";
					word = "";
				}
				cout << Str[i];
			}
		}
		cout << endl;
	}
}
