#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using i64 = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  for (int tc=1; tc<=T; ++tc) {
    cout << "case " << tc << ": ";
    i64 N;
    int odds = -1LL;
    cin >> N;
    while (! (N&1LL) ) N >>= 1; 
    i64 sr = sqrt(N);
    for (i64 d = 1LL; d <= sr; ++d) {
      if (N % d) continue;
      i64 od = N / d;
      odds += (d == od) ? 1LL : 2LL;
    }
    cout << odds << "\n";
  }

  return 0;
}

