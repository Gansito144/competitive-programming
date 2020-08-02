#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, prv = INT_MAX, now, ans = 0, cnt;
  cin >> n;
  while(n--) {
    cin >> now;
    if (now <= prv) {
      cnt = 0;
    }
    ans = max(ans, ++cnt);
    prv = now;
  }
  cout << ans << "\n";
  return 0;
}


