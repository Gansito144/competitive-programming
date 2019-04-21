#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

i64 zeros(i64 d) {
  i64 r = 0LL, p = 1LL;
  for (i64 i=1; i<d; ++i) {
    r += (d-i) * p * 9LL;
    p *= 10LL;
  }
  return r;
}

i64 digits(i64 X) {
  i64 d = 0LL;
  while (X > 0LL) {
    ++d;
    X /= 10LL;
  }
  return d;
}


int main () {
  i64 N, ans = 0, d;
  cin >> N;
  d = digits(N);
  ans += N * d;
  ans -= zeros(d);
  cout << ans << endl;
  return 0;
}

