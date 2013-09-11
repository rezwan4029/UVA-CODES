#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char y[10000];
void reverse(char *x,int len){
    int i , j = 0;
    for(i = len-1 ; i >= 0 ; i--,j++)
        y[j] = x[i];
        y[len] = '\0';
}
int main()
{
    int i,len,k;
    char x[10000];
    char a[10000];
    while( gets(a))
    {
        if( strcmp(a,"DONE") == 0 )break;
        len = strlen(a);
        for(i = k = 0 ; i < len ; i++){
              a[i] = tolower(a[i]);
              if( isalpha(a[i]) )x[ k++ ] = a[i];
        }
        x[k] = '\0';
        reverse(x,k);
        if( strcmp(x,y) == 0 )printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}
