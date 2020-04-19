#include<iostream>
#include<vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector <int> l(m), ans(m), R(m);
  bool can = true;
  for (int i=0; i<m; ++i) {
    cin >> l[i];
    if (i + l[i] > n) {
      can = false;
      break;
    }
  }
  int last = n;
  for (int i=m-1; i>=0; --i) {
    R[i] = min(last - 1, n - l[i]);
    last = R[i];
    if (last < 0) {
      can = false;
      break;
    }
  }
  int empty = 0;
  for (int i=0; i<m; ++i) {
    ans[i] = min(empty, R[i]);
    empty = ans[i] + l[i];
  }
  if (empty < n) can = false;
  if (!can) cout << "-1";
  else {
    for (const int &ai: ans) cout << ai+1 << " ";
  }
  cout << "\n";
  return 0;
}


