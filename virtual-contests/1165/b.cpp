#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int n;
  cin >> n;
  vector <int> v(n);

  for (int &vi:v) cin >> vi;
  sort(v.begin(), v.end());

  int ans = 1, L;
  while (L < n) {
    while (L < n && v[L] < ans) ++L;
    if (L < n && v[L] >= ans) {
      ++ans; ++L;
    }
  }
  cout << ans-1 << endl;
  return 0;
}

