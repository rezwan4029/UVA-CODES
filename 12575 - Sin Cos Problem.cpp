#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926535897932384626433832795

double A,B;

double F(double tht )
{
    return (   A*sin(tht) + B*cos(tht) );
}

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
      scanf("%lf %lf",&A,&B);

      double Theta = atan2(A,B);
      if( Theta < 0 ) Theta = Theta + PI +PI;
      printf("%.2lf %.2lf\n",Theta,F(Theta));

  }
  return 0;
}
