#include<stdio.h>
int main()
{
    int a[10005]={0},left,right,height,i,rightMost=0;
    while(scanf("%d%d%d",&left,&height,&right)!=EOF)
    {
        for(i=left;i<right;i++)
        {
            if(height>a[i])a[i]=height;
        }
        if(right>rightMost)rightMost=right;
    }
    for(i=1;i<rightMost;i++)
    {
        if(a[i] != a[i - 1])    printf("%d %d ", i, a[i]);
    }
    printf("%d 0\n",rightMost);
    return 0;
}
