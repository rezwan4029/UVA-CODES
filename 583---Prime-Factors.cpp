# include<cstdio>
using namespace std;

# define size 5000
long prime[size];
void generate_prime(){
    int i,j;
      long num;
      prime[0]=2;
      prime[1]=3;
      prime[2]=5;
      for(i=3,num=7;i<size;i++,num++){
        while(1){
              for(j=0;prime[j]<=num/2;j++)
                if((num%prime[j])==0){
                      num++;
                      break;
                    }
                  if(prime[j]>num/2)
                    break;
                }
            prime[i]=num;
          }
    }

int main(){
    long g;
    int i;
    generate_prime();
      while(scanf("%ld",&g)==1 && g){
        printf("%ld =",g);
        if(g<0){
              printf(" -1 x");
              g*=-1;
            }
        for(i=0;i<size && g>1;i++)
              while((g%prime[i])==0){
                printf(" %ld",prime[i]);
                g/=prime[i];
                if(g>1)
                      printf(" x");
                else
                      printf("\n");
                  }
            if(i==size && g>1)
                  printf(" %ld\n",g);
          }
      return 0;
    }
