#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector <int> v(n);
  for (int &vi : v) cin >> vi;
  int ans = 0, nxt = 0;
  sort (v.begin(), v.end());
  for (int i=0; i<n; ++i) {
    while (nxt < n && v[nxt] <= v[i]) ++nxt;
    if (nxt == n) break;
    ++ans;
    ++nxt;
  }
  cout << ans << endl;
  return 0;
}

