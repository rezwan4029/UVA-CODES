#include<stdio.h>
#include <stdlib.h>

int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}

int w[25],m,n;

int sol;

void sum_of_subset(int s,int k,int r)
{

   if(s+w[k]==m)
     {
        sol=1;
        return;
     }

   else if( s+w[k] + w[k+1] <= m)        sum_of_subset( s+w[k], k+1, r-w[k] );

   if(( s+r-w[k]>=m) && (s+w[k+1]) <=m ) sum_of_subset(s,k+1,r-w[k]);

}

int main()
{
    int sum,i,T;
    scanf("%d",&T);
    
    while(T--)
    {
        scanf("%d %d",&m,&n);
        sum=0;
        for(i=0;i<n;i++) {scanf("%d",&w[i]); sum=sum+w[i];}

        qsort (w,n,sizeof(int),aComp);
        sol=0;

        if(m==0)
        {
            printf("YES\n");
            continue;
        }

        if(sum < m || w[0]>m)
        {
           printf("NO\n");
        }
        else
        {
            sum_of_subset(0,0,sum);
            if(sol)printf("YES\n");
            else printf("NO\n");
        }

    }
    return 0;
}
