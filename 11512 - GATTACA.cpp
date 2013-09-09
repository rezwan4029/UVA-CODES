/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 10109999990
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64 long long
#define i64U unsigned long long
#define DB double
#define LD long double
#define EPS 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define II ({int a; scanf(" %d", &a); a;})
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL ({i64 a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795

#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)


int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;



#define MAXN  1005
#define MAXLG 20

string A;
struct answer{ int start,len,repeat;}res;
int P[MAXLG][MAXN], N, i, stp, cnt;
//int  suffix_array[MAXN];
struct entry {
    int nr[2], indx;
} L[MAXN];

int cmp (struct entry a, struct entry b) {
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int lcp (int x, int y) {
    int k, ret = 0;
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
        if (P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}


void suffixArray () {
    for (N = A.length(), i = 0; i < N; i ++) P[0][i] = A[i] - 'a';
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1) {
        for (i = 0; i < N; i ++) {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].indx = i;
        } sort(L, L + N, cmp);
        for (i = 0; i < N; i ++)
            P[stp][L[i].indx] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].indx] : i;
    }
}

void computeLCP() {
    int j;
    res.repeat = res.len =  0 ;
    for(i = 0; i < N; i++)
        for( j = i + 1 ; j < N ;j++){
                int len = lcp(L[i].indx, L[j].indx) ;
                if(res.len < len ){
                    res.len = len ;
                    res.start = L[i].indx; // saving the starting of occurance
                    res.repeat = j - i +1;
                }
                else if(res.len == len ){
                    if( j-i+1 > res.repeat){
                        res.repeat = j - i +1 ;
                        res.start = L[i].indx; // saving the starting of occurance
                    }
                }
            }
}

int main () {
    int Test = II ;
    while(Test--)
    {
        cin >> A;
        suffixArray();
        computeLCP();
        if(res.len == 0) cout << "No repetitions found!" << endl;
		else cout << A.substr(res.start,res.len) << " " << res.repeat << endl;

    }
   // system("pause");
    return 0;
}
