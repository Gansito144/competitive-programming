#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;
using i64 = long long int;
using ii = pair<i64, i64>;
using node = pair<ii, i64>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 oo = 1e16;

  int N, M, A, B;
  i64 L, C;
  cin >> N >> M;
 
  vector < vector<node> > G(N + 1);

  for (int i = 0; i < M; ++i) {
    cin >> A >> B >> L >> C;
    G[ A ].push_back({{L, C}, B});
    G[ B ].push_back({{L, C}, A});
  }

  // Dijkstra FTW
  priority_queue<node, vector<node>, greater<node>> PQ;
  i64 ans = 0LL;
  vector <i64> dist(N + 1, oo);
  vector <i64> cost(N + 1, oo);
  PQ.push({ {0LL, 0LL}, 1});

  while (!PQ.empty()) {
    tie(L, C) = PQ.top().first;
    int u = PQ.top().second;
    PQ.pop();
    if (L > dist[ u ]) continue;
    if (L == dist[ u ] && C > cost[ u ]) continue;
    // cout << "L:" << L << " C:" << C << " u:" << u << endl;
    dist[ u ] = L;
    cost[ u ] = C;
    for (const node &n : G[u]) {
      int v = n.second;
      i64 ll, cc;
      tie(ll, cc) = n.first; 
      if ((dist[ v ] == -1LL) || ((dist[ u ] + ll) < dist[ v ]) ||
          (dist[ u ] + ll == dist[v] && cc < cost[v])) {
        PQ.push({{dist[ u ] + ll, cc}, v});
      }
    }
  }

  for (int u = 1; u <= N; ++u) ans += cost[ u ];
  cout << ans << endl;

  return 0;
}

