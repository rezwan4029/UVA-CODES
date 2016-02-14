#include <bits/stdc++.h>
using namespace std;

int main(){
    int correct;
    while(scanf("%d",&correct) != EOF){
        int ans = 0 ;
        for(int i = 0 ; i < 5 ; i++){
            int x;
            scanf("%d",&x);
            ans += ( x == correct );
        }
        printf("%d\n",ans);
    }
}
