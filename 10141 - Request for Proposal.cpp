#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct proposal{
    double price ;
    int item,pos;
    string Str;
};
bool cmp(proposal a , proposal b){
    if(a.item > b.item ) return true;
    if(a.item == b.item && a.price < b.price ) return true;
    if(a.item == b.item && a.price == b.price && a.pos < b.pos ) return true ;
    return false;
}
int main()
{
    int n , p ,cs = 1;
    char s[207];
    proposal a[1007];
    while(scanf("%d %d",&n,&p)){
        if( n == 0 && p == 0 ) break ;
        if(cs != 1 ) cout << endl;
        getchar();
        for(int i = 0 ; i < n ; i++) gets(s);
        for(int i = 0 ; i < p ; i++)
        {
            gets(s);
            a[i].Str = s ;
            int items ; double price ;
            scanf("%lf %d",&price,&items);
            getchar();
            for(int k = 0 ; k < items ; k++ ) gets(s);
            a[i].item = items;
            a[i].price = price;
            a[i].pos = i;
        }
        sort(a,a+p,cmp);
        
        printf("RFP #%d\n",cs++); cout << a[0].Str << endl;
    }
}
