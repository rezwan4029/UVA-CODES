#include <stdio.h>

int num[6] ;
int flag ;
int vis[6] ;
void dfs(int cur , int sum)
{

  int i;
  if(sum == 23 && cur ==5)
  {
       flag = 1 ;  return ;
  }
  else{
    for(i = 0 ; i < 5 ; i++){
       if(!vis[i]){
           vis[i] = 1 ;
           dfs(cur + 1 , sum + num[i]) ;
           dfs(cur + 1 , sum * num[i] ) ;
           dfs(cur + 1 , sum - num[i] ) ;
           vis[i] = 0 ;
       }
    }
 }

}
int main()
{
    int a,b,c,d,e,i;
     while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e))
     {

         if(a==0 && b==0 && c==0 && d==0 && e==0)return 0;
         num[0]=a,num[1]=b,num[2]=c,num[3]=d,num[4]=e;

         flag = 0 ;
         for(i =0 ;i<5;i++ )
         {
             vis[i]=1;
             dfs(1,num[i]) ;
             vis[i]=0;
         }
         if(flag)
         printf("Possible\n");
         else  printf("Impossible\n");
    }

}
