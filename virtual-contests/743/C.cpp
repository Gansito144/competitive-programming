#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 x, y, z, n, num, den;
  bool ans = false;

  cin >> n;

  x = n;
  y = n + 1LL;
  z = x * y;

  num = (x * y * z) << 1;
  den = x*y + x*z + y*z;

  if (n == 1) cout << "-1" << endl;
  else cout << x << " " << y << " " << z << endl;

  return 0;
}
