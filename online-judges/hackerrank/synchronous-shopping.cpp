#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <memory.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> node;

const int KMaxN = 1003; 
const int KInf  = 2e9;

int msk[KMaxN];
int dis[KMaxN << 1][KMaxN];
deque <ii> G[KMaxN];

int main() {
  int N, M, K;
  
  //Read centers, roads and fishes
  scanf("%d %d %d",&N,&M,&K);
  //Read fishes in each store
  for(int i=0; i<N; ++i) {
    int types, fish;
    scanf("%d",&types);
    while(types--) {
      scanf("%d",&fish);
      --fish;
      msk[i] |= (1<<fish);
    }
  }
  //Read roads and weights
  while(M--) {
    int u, v, w;
    scanf("%d %d %d",&u,&v,&w);
    --u; --v;
    G[u].pb( mp(v, w) );
    G[v].pb( mp(u, w) );
  }
  // Calculate Dijkstra with different mask;
  memset(dis, -1, sizeof dis);
  priority_queue <node, deque<node>, greater<node> > PQ;
  PQ.push(mp(mp(0,msk[0]),0));
  dis[msk[0]][0] = 0;
 
  while(!PQ.empty()) {
    int old_msk = PQ.top().F.S;
    int u = PQ.top().S;
    PQ.pop();
    for(int i=0; i<G[u].size(); ++i) {
      int v = G[u][i].F;
      int w = G[u][i].S;
      int new_msk = old_msk | msk[v];
      if(  (dis[new_msk][v] == -1) ||
           ((dis[old_msk][u]+w)<dis[new_msk][v])
        ) {
        dis[new_msk][v] = dis[old_msk][u] + w;
        PQ.push( mp( mp(dis[new_msk][v], new_msk), v) );
      }
    } 
  }

  int ans = KInf;
  // Make all possible combinations and take the best
  for(int mi=0; mi<(1<<K); ++mi) {
    for(int mj=0; mj<(1<<K); ++mj) {
      // Valid when all bits are covered
      if( (mi|mj) != ((1<<K) - 1)) continue;
      if(dis[mi][N-1] == -1) dis[mi][N-1] = KInf;
      if(dis[mj][N-1] == -1) dis[mj][N-1] = KInf;
      int tim = max(dis[mi][N-1], dis[mj][N-1]);
      if(tim < ans) {
        ans = tim;
        // printf("Possible with mi(%d) and mj(%d)\n",mi,mj);
      }
    }
  }

  // Print result
  printf("%d\n",ans);
  return 0;
}



