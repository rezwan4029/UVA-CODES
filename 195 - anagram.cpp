#include <stdlib.h>
#include <algorithm>
#include<stdio.h>
#include<iostream>
#include<ctype.h>
using namespace std;

bool comp(const char &a, const char &b) {
    int delta = tolower(a) - tolower(b);
    return delta ? delta < 0 : a <b;
}

char msg[10000];
int main()
{
    int len,t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
      scanf("%s",&msg);
      len=0;
      while(msg[len])len++;
      sort(msg,msg+len,comp);
      printf("%s\n",msg);
      while(next_permutation(msg,msg + len,comp))
      printf("%s\n",msg);
    }
    return 0;
}
