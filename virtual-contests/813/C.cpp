#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>
#include <memory.h>
     
using namespace std;
     
const int MxN = 200005;
int ans, N, X;
bool can;
vector <int> G[MxN];
int dis[MxN][2];

void bfs(int n, int p) {
  for(int i=1; i<=N; ++i) dis[i][p] = -1;
  queue <int> Q;
  Q.push(n);
  dis[n][p] = 0;
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if(p == 1) {
      if(dis[u][0] < dis[u][p]) {
        ans = max(ans, dis[u][p]);
      }
    }

    for(int i=0; i<G[u].size(); ++i) {
      int v = G[u][i];
      if(dis[v][p] == -1) {
        Q.push(v);
        dis[v][p] = dis[u][p]+1;
      }
    }
  }
}
     
int main() {
  int u, v;

  scanf("%d %d",&N, &X);
  for(int i=1; i<N; ++i) {
    scanf("%d %d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  bfs(X, 0);
  bfs(1, 1);

  printf("%d\n",ans << 1);
  return 0;
}
