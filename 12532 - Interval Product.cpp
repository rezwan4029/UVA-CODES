#include<stdio.h>

int tree[ 400040 ];


int Fn(int x)
{
	if(x > 0)	return  1;
	if(x < 0)   return -1;
	return 0;
}

void build(int node,int left,int right)
{
	if(left==right){

	    int x ; scanf("%d",&x);
		tree[node] = Fn(x);
		return;
	}
	int mid=(left+right)/2;
	build(2*node,left,mid);
	build(2*node+1,mid+1,right);
	tree[node]= tree[2*node] * tree[2*node+1];
}

int Query(int node,int left,int right,int start,int end)
{
	if(left==start && right==end)	return tree[node];

	int mid=(left + right) / 2;

	if(end<=mid)	return Query( 2*node , left , mid , start , end );

	if(start>mid)	return Query( 2*node+1 , mid+1 , right , start , end );

	else{
		int x = Query( 2*node , left , mid , start , mid );
		int y = Query( 2*node+1 , mid+1 , right , mid+1, end );
		return (x*y);
	}
}

void Update(int node ,int left,int right,int pos ,int val)
{
    if(pos==left && left==right){
        tree[ node ] = Fn(val);
        return ;
    }
    int mid = ( left + right ) / 2 ;

    if(pos <= mid )  Update( node*2 ,left ,mid ,pos ,val);
    else             Update( node*2 +1 , mid+1 ,right ,pos ,val);

    tree[node] = tree[node*2] * tree[node*2+1];
}

int main()
{
	int n,Q;
	char ques[2];
	//freopen("in.txt","r",stdin);
	while(scanf("%d %d",&n,&Q) == 2)
	{
		build(1,1,n);
		while(Q--)
		{
			scanf("%s",&ques);
			if(ques[0] == 'C')	{
                int pos , val;
                scanf("%d %d",&pos,&val);
                Update(1,1,n,pos,val);
			}
			else{
                int p,q;
                scanf("%d %d",&p,&q);
				int ret = Query(1,1,n,p,q);
				if(ret<0)	printf("-");
				else if(ret>0)	printf("+");
				else	printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
