#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main() {
  i64 T, n, l , r;
  cin >> T;
  while (T--) {
    cin >> n >> l >> r;
    i64 d = (n / l);
    cout << ((d*r >= n && l<=n) ? "Yes" : "No") << endl;
  }
  return 0;
}

