#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, t, s, d, best = 123456789, ans = 1, dist;

  cin >> n >> t;

  for (int i=0; i<n; ++i) {
    cin >> s >> d;
    if (s >= t) dist = (s-t);
    else {
      dist = ((d - (t - s) % d) % d);
    }
    if (dist < best) {
      ans = i + 1;
      best = dist;
    }
  }
  cout << ans << endl;
  return 0;
}

