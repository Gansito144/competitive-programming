#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, s, t, ans = 0, u, v;
  cin >> n >> m >> s >> t;
  set <int> G[1003];
  vector <int> ds(n+1, -1), dt(n+1, -1);
  while (m--)
  {
    cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
  }
  // BFS on source
  ds[s] = 0;
  queue <int> Q;
  Q.push(s);
  while (!Q.empty())
  {
    u = Q.front(); Q.pop();
    for(const int &w : G[u])
    {
      if (ds[w] == -1)
      {
        ds[w] = ds[u] + 1;
        Q.push(w);
      }
    }
  }
  // BFS on target
  dt[t] = 0;
  Q.push(t);
  while (!Q.empty())
  {
    u = Q.front(); Q.pop();
    for(const int &w : G[u])
    {
      if (dt[w] == -1)
      {
        dt[w] = dt[u] + 1;
        Q.push(w);
      }
    }
  }
  for (u=1; u<=n; ++u)
    for (v=u+1; v<=n; ++v)
    {
      if (G[u].find(v) != G[u].end())
        continue;
      if ((ds[u] + dt[v] + 1) < ds[t]
       || (dt[u] + ds[v] + 1) < dt[s])
        continue;
      ++ans;
    }
  cout << ans << endl;
  return 0;
}

