#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2003;
vector< int > g[N];
int d[N];

int main() {
	int n, v, ans=0;
	queue < int > q;

	scanf("%d",&n);
	for( int u=0; u<n; ++u) {
		scanf("%d",&v);
		if(-1 == v) q.push(u);
		else g[v-1].push_back(u);
	}
	
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(int i=0; i<g[v].size(); ++i) {
			int u = g[v][i];
			d[u] = d[v]+1;
			q.push(u);
			ans = max(d[u], ans);  
		}
	}
	printf("%d\n",ans+1);
    return 0;
}

