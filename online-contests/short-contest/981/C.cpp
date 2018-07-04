#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, u, v;
  cin >> n;

  vector <vector<int>> G(n+1, vector<int>(0));
  vector <int> deg(n+1, 0), sol, seen(n+1, 0);

  for (int i=1; i<n; ++i)
  {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
    ++deg[u];
    ++deg[v];
  }

  int root = 1;

  for (u=2; u<=n; ++u) 
  {
    if (deg[u] > deg[root])
      root = u;
  }

  bool can = true;
  seen[root] = 1;

  for (const int &s : G[root])
  {
    u = root;
    stack <int> st;
    st.push(s);
    while (!st.empty())
    {
      v = st.top(); st.pop();
      if (v != root && deg[v] > 2)
      {
        can = false;
        break;
      }
      seen[v] = 1;
      for (int i=0; i<G[v].size(); ++i)
      {
        int w = G[v][i];
        if (w == u) continue;
        st.push(w);
        u = v;
        break;
      }
    }
    if (!can) break;
    sol.push_back(v);
  }

  for (u=1; u<=n; ++u)
    if (seen[u] == 0)
      can = false;

  if (can)
  {
    cout << "Yes\n" << sol.size() << "\n";
    for (const int &si : sol)
      cout << root << " " << si << "\n";
  }
  else cout << "No\n";


  return 0;
}


