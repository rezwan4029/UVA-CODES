#include<stdio.h>
#include<string.h>
#include<math.h>
char num[20],len;
int baseCheck(int base)
{
    int i,x;
    for(i=0; i<len; i++)
    {
        if(num[i]>='A'&& num[i]<='F')x=10+num[i]-'A';
        else x=num[i]-48;
        if(x>=base)return 1;
    }
    return 0;
}
unsigned long long ConvertToDecimal(int b)
{
    int i,POW=0;
    unsigned long long n=0;
    for(i=len-1; i>=0; i--)
    {
        if(num[i]>='A'&& num[i]<='F')n=n+ (10+num[i]-'A')*pow(b,POW);
        else  n=n+(num[i]-48)*pow(b,POW);
        POW++;
    }
    return n;
}
void BaseConverstion(unsigned long long n,int b)
{
    if(n==0) return;
    BaseConverstion(n/b,b);
    int x=n%b;
    if( x == 10 )printf("A");
    else if( x == 11 ) printf("B");
    else if( x == 12 ) printf("C");
    else if( x == 13 ) printf("D");
    else if( x == 14 ) printf("E");
    else if( x == 15 ) printf("F");
    else printf("%d",x);
}
int main()
{
    int base , convbase ;
    unsigned long long n ;
    while(scanf("%d %d %s",&base,&convbase,&num)==3)
    {
        len = strlen(num);
        if(baseCheck(base))
        {
            printf("%s is an illegal base %d number\n",num,base);
            continue;
        }
        n=ConvertToDecimal( base );
        printf("%s base %d = ",num,base);
        if( n == 0 )printf("0");
        else BaseConverstion( n , convbase );
        printf(" base %d\n" , convbase );
    }
    return 0;
}
