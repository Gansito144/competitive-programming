#include <stdio.h>
#include <memory.h>
#include <queue>
#include <iostream>

using namespace std;

deque <int> G[1003];
int color[1003];

void dfs(int u, int col, bool &can) {
  color[u] = col;
  for(int i=0; i<G[u].size(); ++i) {
    int v = G[u][i];
    if(color[v] != -1) {
      if (color[v] + color[u] != 1) {
        can = false;
        return ;
      }
    } else {
      dfs(v, 1-col, can);
    }
  }
}

int main() {
  int n, m;
  int u, v;

  scanf("%d %d\n",&n,&m);
  for(int i=0; i<m; ++i) {
    scanf("%d %d",&u,&v);
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  memset(color, -1, sizeof color);
  bool can = true;
  for(int i=0; i<n; ++i) {
    if(color[i] == -1) {
      dfs(i, 0, can);
    } 
  }
  puts(can?"YES":"NO");
  return 0;
}

