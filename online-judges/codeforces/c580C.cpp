#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

const int N = 100001;
int   hasCat [N];
int ans, seen[N];
deque <int> G[N];

void dfs( int u, int cCats, int& mxCats) {
	seen[u] = true;
	bool leaf = true ;
	for(int i=0; i<G[u].size(); i++) {
		int v = G[u][i];
		if(seen[v]) continue;
		leaf=false;
		if(hasCat[v]) {
			if(cCats+1 > mxCats) continue;
			dfs(v, cCats+1, mxCats);
		} else {
			dfs(v, 0 , mxCats);
		}
	}
	if(leaf) {
		++ans;
	}
}

int main() {
	int n, m, u, v;
	
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&hasCat[i]);
	for(int i=1; i<n; i++) {
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs( 1, hasCat[1], m);
	printf("%d\n",ans);
	
	return 0;
}