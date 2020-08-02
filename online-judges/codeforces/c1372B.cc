#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int a = 1, b = n-1;
    for (int d=2; d*d<=n; ++d) {
      if (n % d == 0) {
        a = n / d;
        b = n - a;
        if (a > b) swap(a, b);
        break;
      }
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}

