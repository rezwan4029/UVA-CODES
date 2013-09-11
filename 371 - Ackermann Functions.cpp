
#include<stdio.h>

int main()
{
    long l,h,cnt,cnt_M,i,j,m;
    while(scanf("%ld%ld",&l,&h))
    {
        if(l==0 &&h==0)break;
        if(l>h)
        {
            cnt=h;
            h=l;
            l=cnt;
        }
        cnt_M=0;
        for(i=l; i<=h; i++)
        {
            cnt=0;
            j=i;
            while(1)
            {
                if(j%2==0)j=j/2;
                else
                    j=3*j+1;
                cnt++;
                if(j==1)break;
            }
            if(cnt>cnt_M)
            {
                cnt_M=cnt;
                m=i;
            }
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",l,h,m,cnt_M);
    }
    return 0;
}
