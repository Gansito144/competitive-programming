/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use interval tree  
 * with bitmask to store data.
*/

#include <cstdio>
#include <cstring>

using namespace std;

int s[123456];

typedef struct intervalTree *ptrIntervalTree;

struct intervalTree{
	int D;
	int L, R;
	ptrIntervalTree izq, der;

	// constructor
	intervalTree(){}
	intervalTree(int L, int R):L(L),R(R) {
		izq = der = NULL;
		if(L==R) D = 1<<(s[L]);
		else {
			int md = (L+R)>>1;
			izq = new intervalTree(L, md);
			der = new intervalTree(md+1, R);
			D = izq->D | der->D;
		}
	}
	int query(int a, int b) {
		if(R<a || b <L) return 0LL;
		if(a<=L && R<=b) return D;
		return izq->query(a,b)|der->query(a,b);
	}
	// Destructor
	~intervalTree() {
		delete izq;
		delete der;
	}
};

int main() {
	int n, q, l , r;
	while(scanf("%d",&n)!=EOF){
		for(int i=1; i<=n; ++i) {
			scanf("%d",&s[i]);
		}
		intervalTree it(1,n);
		scanf("%d",&q);
		while(q--) {
			scanf("%d %d",&l,&r);
			printf("%d\n",__builtin_popcount(it.query(l,r)));
		}
	}
	return 0;
}