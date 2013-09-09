#include <stdio.h>
#include <string.h>
#include <iostream>
#include <utility>
#include <algorithm>
#define  pss pair< string , string >
using namespace std;

int main()
{
    int test,i;
    string s1,s2;
    scanf("%d",&test);
    while(test--)
    {
        
        int sz ;
        pss Dict[1005];
        scanf("%d",&sz);
        for( i = 0 ; i < sz ; i++ ){
            cin >> s1;
            s2 = s1 ;
            sort(s2.begin(),s2.end());
            Dict[i] = pss(s1,s2);
        }

        while(true){
            cin>>s1 ;
            if( s1 == "END" )break;
            printf("Anagrams for: "); cout << s1 <<endl;
            s2 = s1;
            sort(s2.begin(),s2.end());

            for( i = 0 ; i< sz ; i++ ){
                if(s2==Dict[i].second)break;
            }
            if( i == sz ) {
                printf("No anagrams for: ");cout<<s1<<endl;
            }
            else{
                
                int c = 1 ;
                for( ; i < sz ; i++ )
                {
                    if( Dict[i].second == s2){
                    printf("%3d) ",c++); cout << Dict[i].first << endl;
                    }
                }
            }
        }
        
        if( test ) cout<< endl;

    }
}
