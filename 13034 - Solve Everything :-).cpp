#include <bits/stdc++.h>
using namespace std;

int main(){
    int T ;
    scanf("%d",&T);
    for( int cs = 1 ; cs <= T ; cs++ ){
        bool yes = true;
        for( int i = 0 ; i < 13 ; i++ ){
            int x;
            scanf("%d",&x);
            yes &= ( x > 0);
        }
        printf("Set #%d: %s\n",cs, yes? "Yes" : "No");
    }
}
