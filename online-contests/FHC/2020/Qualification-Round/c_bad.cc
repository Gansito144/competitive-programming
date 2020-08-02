#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using ii = pair<int,int>; // node, new pos
using vii = vector<ii>;
using mivii = map<int, vii>;
using miii = map<ii, int>;

int dfs(mivii &G, miii &dp, int pos, int parent) {
  ii n = make_pair(pos, parent);
  if (dp[n]) return dp[n];
  int &res = dp[n];
  for (const auto &node : G[pos]) {
    int u = node.first;
    int h = node.second;
    if (u == parent) continue;
    int nres = h + dfs(G, dp, pos + h, u);
    res = max(res, nres);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc) {
    int n, mx = 0, h, p;
    mivii G;
    miii dp;
    cin >> n;
    for (int i=0; i<n; ++i) {
      cin >> p >> h;
      G[p-h].push_back(make_pair(i, h));
      G[p].push_back(make_pair(i, h));
    }
    for (const auto &it  : G) {
      int nmx = dfs(G, dp, it.first, -1);
      mx = max(mx, nmx);
    }
    cout << "Case #" << tc << ": " << mx << "\n";
  }

  return 0;
}

