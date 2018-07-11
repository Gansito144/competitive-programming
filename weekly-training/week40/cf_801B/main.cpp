#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string a, b, ans;

  cin >> a >> b;

  int n = int(a.size());
  ans = b;
  for (int i=0; i<n; ++i) {
    if (b[i] > a[i]) {
      ans = "-1";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

