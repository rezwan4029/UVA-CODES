#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795
#define sq(a) ((a)*(a))
int main()
{
    double r = double(1)/double(5) ;
    double w = double(6)/double(10) ;
    int n,cs =1,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        
        double circle = pi * double(n)*r  * double(n)*r ;

        double rect =  double(n)*  double(n)*w  - circle ;

        printf("%.2lf %.2lf\n",circle ,rect );

    }
    return 0;
}
