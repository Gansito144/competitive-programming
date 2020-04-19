#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector <int> x(n);
  for (int &xi: x) cin >> xi;
  sort(x.begin(), x.end());
  int q, mi;
  cin >> q;
  while (q--) {
    cin >> mi;
    const int ans = upper_bound(x.begin(), x.end(), mi) - x.begin();
    cout << ans << "\n";
  }
  return 0;
}


