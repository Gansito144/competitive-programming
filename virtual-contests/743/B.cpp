#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 n, k;
  cin >> n >> k;

  while (true) {
    i64 middle = (1LL << n);
    if (k == middle) {
      cout << (n+1LL) << endl;
      return 0;
    }
    if (k > middle) k -= (middle);
    --n;
  }

  return 0;
}

