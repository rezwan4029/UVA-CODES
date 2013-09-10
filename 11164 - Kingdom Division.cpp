#include<stdio.h>

int main()
{
  int cs=1;
  double a,b,c;
  while(scanf("%lf %lf %lf",&a,&b,&c))
    {


/**
Let d1 be the area of triangle XEF and d2 be the area of triangle AEF.
Then d1 and d2 can be calculated from the following equations:
d1/a = c/b and (a+d1)/d2 = (a+b)/(c+d1+d2).
The result will be d = d1+d2.
*/
        if(a==-1) break;
        printf("Set %d:\n",cs++);
        double d1=(a*c)/b;
        if( b==0.0 || b==d1)
        {
          printf("Poor King!\n");
          continue;
        }

        double d2=(a+d1)*c +(a+d1)*d1;
        d2=d2/(b-d1);
        double ans=d1+d2;
        (ans>0) ?printf("%.4lf\n",ans):printf("Poor King!\n");
    }
    return 0;
}
