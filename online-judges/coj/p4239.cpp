#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

#define W first
#define E second
#define U first
#define V second

using namespace std;
using edge = pair<int,int>; 
using node = pair<int, edge>;
using i64 = long long int;

const int MAXN = 10004;
char line[102];
int p[MAXN], rk[MAXN];

int find(int x) {
  if (x != p[x])
    p[x] = find(p[x]);
  return p[x];
}

void link(int x, int y) {
  if (rk[x] > rk[y])
    p[y] = x;
  else {
    p[x] = y;
    if (rk[x] == rk[y])
      rk[y] = rk[y] + 1;
  }
}

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);

  int T, N, M, u, v, w, ccs, pu, pv;
  sscanf(gets(line),"%d",&T);

  for (int tc=0; tc<T; ++tc) {
    sscanf(gets(line),"%d",&N);
    sscanf(gets(line),"%d",&M);
    for (int i=1; i<=N; ++i) {
      p[i] = i;
      rk[i] = 0;
    }
    ccs = N;
    while (M--) {
      sscanf(gets(line),"%d %d %d", &u, &v, &w);
      pu = find(u);
      pv = find(v);
      if (pu != pv) {
        --ccs;
        link(pu, pv);
      }
    }
    sscanf(gets(line),"%d",&M);
    vector <node> edges(M);
    for(node &ei : edges) {
      sscanf(gets(line),"%d %d %d", &u, &v, &w);
      ei = {w, {u,v}};
    }
    if (ccs == 1) {
      // cout << "Ahorita no joven\n";
      puts("Thank you, Goodbye");
    } else {
      sort(edges.begin(), edges.end());
      i64 ans = 0LL;
      for (const node &ei: edges) {
        w = ei.W; u = ei.E.U; v = ei.E.V;
        pu = find(u);
        pv = find(v);
        if (pu != pv) {
          ans += w;
          --ccs;
          link(pu, pv);
        }
      }
      if (ccs != 1) {
        // cout << "Mejor contrata a otro equipo\n";
        puts("You better hire someone else");
      } else {
        printf("%lld\n", ans);
      }
    }
  }

  return 0;
}

