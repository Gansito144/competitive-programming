#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;

  cin >> n >> m;
  vector <int> v(m+2, 0);

  int l,r;
  while (n--) {
    cin >> l >> r;
    ++v[l];
    --v[r+1];
  }
  n = 0;
  for (int i=1; i<=m; ++i) {
    v[i] += v[i-1];
    if (!v[i]) ++n;
  }

  cout << n << endl;
  for (int i=1; i<=m; ++i) {
    if (!v[i])
      cout << i << " ";
  }
  cout << endl;

  return 0;
}

