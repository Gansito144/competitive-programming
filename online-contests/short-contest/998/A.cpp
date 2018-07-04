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
  vector <int> a(n);
  for (int &ai : a) cin >> ai;
  bool ans = false;
  for (int msk=1; msk<((1<<n) - 1); ++msk) {
    int sa = 0, sb = 0;
    for (int b=0; b<n; ++b) {
      if ((msk>>b)&1) sa += a[b];
      else sb += a[b];
    }
    if (sa != sb) {
      ans = true;
      cout << __builtin_popcount(msk) << endl;
      for (int b=0; b<n; ++b) {
        if ((msk>>b)&1) cout << b+1 << " ";
      }
      cout << endl;
      break;
    }
  }
  if (!ans) cout << -1 << endl;
  return 0;
}


