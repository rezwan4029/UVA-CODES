#include<stdio.h>
#include<math.h>
int main()
{
    int test,cs=1;
    double u,v,s,t,a;
    while(scanf("%d",&test)&&test)
    {
        if(test==1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            a=(v-u)/t;
            s=(v*v -u*u)/(2*a);
            printf("Case %d: %.3lf %.3lf\n",cs++,s,a);
             continue;
        }
        if(test==2)
        {
            scanf("%lf %lf %lf",&u,&v,&a);
            t=(v-u)/a;
            s=(v*v -u*u)/(2*a);
             printf("Case %d: %.3lf %.3lf\n",cs++,s,t);
             continue;
        }
        if(test==3)
        {
            scanf("%lf %lf %lf",&u,&a,&s);
            v=sqrt(u*u + 2 *a *s);
             t=(v-u)/a;
             printf("Case %d: %.3lf %.3lf\n",cs++,v,t);
            continue;
        }
        if(test==4)
        {
            scanf("%lf %lf %lf",&v,&a,&s);
            u = sqrt(v*v - 2 * a * s );
            t = (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",cs++,u,t);
            continue;
        }
    }
    return 0;
}
