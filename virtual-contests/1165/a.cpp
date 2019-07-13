#include <iostream>
#include <string>

using namespace std;
using i64 = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, x, y, ans = 0;
  string s;
  cin >> n >> x >> y;
  cin >> s;
  
  if (s[n-y-1] != '1') {
    ++ans;
  }
  s[n-y-1] = '0';

  for (int d=n-x; d<n; ++d) {
    if (s[d] == '1') {
      ++ans;
      s[d] = '0';
    }
  }

  cout << ans << "\n";
  return 0;
}

