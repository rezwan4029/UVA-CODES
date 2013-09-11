#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXN 10005

typedef int Item;

int cmp(Item a, Item b){
  return a >= b;

}

int longest(int n, Item *A, Item *S)
{
  int most = 0, mi, i, j, last[MAXN], len[MAXN];

  for(i = 0; i < n; i++)
  {
    len[i] = 1;

    for(j = 0; j < i; j++)
            {

                if(cmp(A[i], A[j]) && len[j]+1 > len[i])
                    {
                        len[i] = len[j]+1;
                        last[i] = j;
                    }
            }
    if(len[i] > most)
    {
      most = len[i];
      mi = i;
    }
  }

  for(i = most-1; i >= 0; i--)
  {
    S[i] = A[mi];
    mi = last[mi];
  }
  return most;
}

int main()
{
  int n, result, i;
  Item A[MAXN], S[MAXN];
  int T,BL=0;
  scanf("%d",&T);
  getchar();getchar();
  char txt[50];

  while(T--)
  {
      n = 0;
      while(gets(txt)){
          if(strlen(txt)==0)break;
          A[n++]=atoi(txt);
      }
      if(BL)printf("\n");
      BL=1;
      result = longest(n, A, S);
      printf("Max hits: %d\n", result);
      for(i = 0; i < result; i++) printf("%d\n", S[i]);
  }
  return 0;
}
