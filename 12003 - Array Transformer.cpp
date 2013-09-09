#include <stdio.h>
#include <stdlib.h>
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
typedef long long int64;

struct node {
	int key, rnk, cnt;
	node *le, *ri;

	node (int key = 0, int rnk = rand ()) : key (key), rnk (rnk), cnt (1), le (0), ri (0) {}
};

class treap {
	typedef node* pNode;
	pNode root;
    int count (pNode temp) { return temp ? temp -> cnt : 0; }
    void updateCnt (pNode temp) { if (temp) temp -> cnt = 1 + count (temp -> le) + count (temp -> ri); }

	void split (pNode temp, pNode &le, pNode &ri, int key) {
		if (!temp) { le = ri = 0; return; }
        if (key < temp -> key ) split (temp -> le, le, temp -> le, key), ri = temp;
        else split (temp -> ri, temp -> ri, ri, key), le = temp;
        updateCnt (temp);
    }

    void merge (pNode &temp, pNode le, pNode ri) {
        if (!le || !ri) temp = le ? le : ri;
        else if (le -> rnk > ri -> rnk) merge (le -> ri, le -> ri, ri), temp = le;
        else merge (ri -> le, le, ri -> le), temp = ri;
        updateCnt (temp);
    }

    void insert (pNode &temp, pNode it) {
        if (!temp) temp = it;
        else if (it -> rnk > temp -> rnk) split (temp, it -> le, it -> ri, it -> key), temp = it;
        else insert ((it -> key < temp -> key) ? temp -> le : temp -> ri, it);
        updateCnt (temp);
    }

    void erase (pNode &temp, int key, int rnk) {
        if (!temp) return;
        if (temp -> key == key) {
        	if (rnk == -1) rnk = temp -> rnk;
        	if (rnk == temp -> rnk) merge (temp, temp -> le, temp -> ri);
        	else erase (temp -> ri, key, rnk);
        } else erase ((key < temp -> key) ? temp -> le : temp -> ri, key, rnk);
        updateCnt (temp);
    }

    int countLess (pNode temp, int key) {
        if (!temp) return 0;
        if (key <= temp -> key) return countLess (temp -> le, key);
        return 1 + count (temp -> le) + countLess (temp -> ri, key);
    }
public:
	treap () { root = 0; }
    void clear () { root = 0 ; }
	void insert (int key, int rnk = rand ()) { insert (root, new node (key, rnk)); }
	void erase (int key, int rnk = -1) { erase (root, key, rnk); }
	int countLess(int key){ return countLess(root,key); }
};

treap tree[300007];
int a[300007];
int n , m , u ;

int add(int idx,int val) {
    while(idx <= n) {
		tree[idx].insert(val);
		idx += (idx & -idx);
	}
}

void del(int idx , int val){
     while(idx <= n) {
		tree[idx].erase(val);
		idx += (idx & -idx);
	}
}

int Query(int idx , int val){
    int s = 0;
	while(idx > 0) {
		s += tree[idx].countLess(val);
		idx -= (idx & -idx);
	}
	return s;
}

inline int nextInt(){
    int x = 0;
    register int c = getc(stdin);
    int sign = 0;
    for( ; ((c < 48 || c > 57) && c != '-'); c = getc(stdin));
    if(c == '-'){
        sign = 1;
        c = getc(stdin);
    }
    for( ; c > 47 && c < 58; c = getc(stdin)) x = (x<<1) + (x<<3) + c - 48;
    if (sign) x = -x;
    return x;
}

int main(){
    while(scanf("%d %d %d",&n,&m,&u)!=EOF){
        For(i,n){
            a[i] = nextInt();
            add(i,a[i]);
        }
        while(m--){
            int l = nextInt() , r = nextInt() , v  = nextInt()  , p = nextInt() ;
            int64 ans = Query(r,v) - Query(l-1,v);
            del(p,a[p]);
            int64 x = ( u * ans ) / (r - l + 1 ) ;
            a[p] = x ;
            add(p,a[p]);
        }
        For(i,n) printf("%d\n",a[i]) ;
        For(i,n)tree[i].clear();
    }
}
