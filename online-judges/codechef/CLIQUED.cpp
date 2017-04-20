#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <utility>

using namespace std;

typedef long long int i64;
typedef pair<i64, int> edge;

const int MaxN = 123456;

i64 dist[MaxN];
priority_queue <edge, deque<edge>, greater<edge> > PQ;
deque <edge> G[MaxN];

int main() {
  int N, K, M, S, nc, a, b;
  i64 X, c;
  bool add_old;


  scanf("%d",&nc);
  for(int tc=1; tc<=nc; ++tc) {
    scanf("%d %d %lld %d %d",&N,&K,&X,&M,&S);

    for(int i=0; i<N; ++i) dist[i] = -1LL;

    // Read new roads
    while(M--) {
      scanf("%d %d %lld",&a,&b,&c);
      --a; --b;
      G[a].push_back(make_pair(c,b));
      G[b].push_back(make_pair(c,a));
    }

    --S;
    PQ.push(make_pair(0LL,S));
    dist[S] = 0LL;
    add_old = true;

    while(!PQ.empty()) {
      a = PQ.top().second;
      c = PQ.top().first;
      PQ.pop();
      // Already improved
      if(c != dist[a]) continue;
      // Add old roads if possible
      if((a<K) && add_old) {
        add_old = false;
        for(int i=0; i<K; ++i) {
          if((dist[i]<0LL) || ((dist[a]+X)<dist[i])) {
            dist[i] = dist[a] + X;
            PQ.push(make_pair(dist[i], i));
          }
        }
      }
      // Add new roads
      for(int i=0; i<G[a].size(); ++i) {
        b = G[a][i].second;
        c = G[a][i].first;
        if((dist[b] < 0LL) || ((dist[a]+c)<dist[b])) {
          dist[b] = dist[a]+c;
          PQ.push(make_pair(dist[b], b));
        }
      }
    }

    // Print ans and clear graph
    for(int i=0; i<N; ++i) {
      printf("%lld%c",dist[i]," \n"[i==(N-1)]);
      if(G[i].size()) G[i].clear();
    }
  }
  return 0;
}

