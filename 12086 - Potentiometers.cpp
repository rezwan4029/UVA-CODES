#include<stdio.h>
#define sz 200005
int data[sz],tree[4*sz],par[sz];

void build(int node,int start,int finish)
{
    if(start==finish)
    {
        tree[node]=data[start];
        par[start]=node;
    }
    else
    {
        int mid=(start+finish)/2;

        build(node*2,start,mid);
        build(node*2+1,mid+1,finish);

        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

int query(int node,int start,int finish,int left,int right)
{
    if(right<start || left>finish)return 0;

    if(start>=left && finish<=right) return tree[node];

    int mid=(start+finish)/2;

    return (query(node*2,start,mid,left,right)+query((node*2+1),mid+1,finish,left,right));
}

void update(int place ,int val)
{
    int node=par[place];
    
    tree[node]=val;
    
    node=node/2;

    while(node)
    {
        tree[node]=tree[node*2]+tree[node*2+1];
        node=node/2;
    }
}

int main()
{
    int n,i,cs=0;
    while(scanf("%d",&n)&&n)
    {
        if(cs)printf("\n");
        printf("Case %d:\n",++cs);
        for(i=1;i<=n;i++)scanf("%d",&data[i]);
        build(1,1,n);

        char q[10];

        while(scanf("%s",&q))
        {
            if(q[0]=='E')break;

            int x,y;

            scanf("%d %d",&x,&y);

            if(q[0]=='M')
            {
                printf("%d\n",query(1,1,n,x,y));
            }
            else
            {
                update(x,y);
            }
        }
    }
    return 0;
}
