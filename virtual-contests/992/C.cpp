#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

const i64 m = 1000000007LL;

i64 pot (i64 e) {
  i64 r;
  if (e == 0) r = 1LL;
  else {
    r = pot (e >> 1);
    r = (r * r) % m;
    if (e & 1LL) r = (2LL * r) % m;
  }
  return r;
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 x, k;

  cin >> x >> k;

  i64 ans;
  if (x == 0LL) ans = 0LL;
  else if (k == 0LL) ans = (x*2LL) % m;
  else {
    i64 two = pot(k);
    i64 R = (x%m * two) % m;
    i64 L = (R - pot(k-1) + m) % m;
    ans = (L + L + 1LL) % m;
  }
  cout << ans << endl;
  return 0;
}

