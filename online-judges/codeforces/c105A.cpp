#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int k, l, m, n, d, ans = 0;
  cin >> k >> l >> m >> n >> d;
  for (int x=1; x<=d; ++x) {
    if (x % k == 0) continue;
    if (x % l == 0) continue;
    if (x % m == 0) continue;
    if (x % n == 0) continue;
    ++ans;
  }
  cout << d - ans << endl;
  return 0;
}

