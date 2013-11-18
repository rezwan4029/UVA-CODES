/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define LL long long
#define LLU unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define inpI ({int a; scanf(" %d", &a); a;})
#define inpD ({DB a; scanf(" %lf", &a); a;})
#define inpLL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
//

using namespace std;

#define MAXV 100005

int in[MAXV+5];

struct ss
{
    int l,lv,r,rv,val;
    ss(int _l=0,int _lv=0,int _r=0,int _rv=0,int _val=0){l=_l,lv=_lv,r=_r,rv=_rv,val=_val;}
}tree[MAXV*4];



void build(int node,int left,int right)
{
    if(left==right)
    {
        tree[node].val=1;
        tree[node].l=in[left];
        tree[node].lv=1;
        tree[node].r=in[right];
        tree[node].rv=1;
        return;
    }

    tree[node].val= -inf;
    int mid=(left+right)/2;

    build(node*2,left,mid);
    build(node*2+1,mid+1,right);

    tree[node].l=tree[node*2].l;
    tree[node].r=tree[node*2+1].r;
    tree[node].lv=tree[node*2].lv;
    tree[node].rv=tree[node*2+1].rv;
    tree[node].val=max(tree[node].val,tree[node*2].val);
    tree[node].val=max(tree[node].val,tree[node*2+1].val);

    if(tree[node*2].r==tree[node*2+1].l)
    {
        int v=tree[node*2].rv+tree[node*2+1].lv;

        if(tree[node*2].l==tree[node*2].r)tree[node].lv=v;

        if(tree[node*2+1].l==tree[node*2+1].r)tree[node].rv=v;

        tree[node].val=max(tree[node].val,v);
    }
}

ss query(int node,int left,int right,int i,int j)
{
    if(i>right||left>j)return ss(-inf,-inf,-inf,-inf,-inf);

    if(i<=left&&j>=right)return tree[node];

    ss q1,q2,Q;
    int mid;

    mid=(left+right)/2;
    q1=query(node*2,left,mid,i,j);
    q2=query(node*2+1,mid+1,right,i,j);

    Q.l=q1.l;
    Q.r=q2.r;
    Q.lv=q1.lv;
    Q.rv=q2.rv;
    Q.val=max(q1.val,q2.val);


    if(q1.r==q2.l &&q1.r!=-inf)
    {
        int T=q1.rv + q2.lv;
        if(q1.l==q1.r)Q.lv=T;
        if(q2.l==q2.r)Q.rv=T;
        Q.val=max(Q.val,T);
    }


    return Q;
}

int main()
{
    int N,i,Q,r,l;
    while(scanf("%d",&N,&Q))
    {
        if(!N)break;
        scanf("%d",&Q);
        for(i=1;i<=N;i++)scanf("%d",&in[i]);
        in[0]= -inf;

        build(1,1,N);


        for(i=1;i<=Q;i++)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,N,l,r).val);
        }
    }
    return 0;
}
