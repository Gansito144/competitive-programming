#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  for(int tc=0; tc <T; ++tc) {
    int n;
    bool one = false;
    string x, a, b;
    cin >> n >> x;
    a = b = x;
    a[0] = b[0] = '1';
    for (int i=1; i<n; ++i) {
      if (one) {
        a[i] = '0';
        b[i] = x[i];
      } else {
        if (x[i] == '1') {
          a[i] = '1';
          b[i] = '0';
          one = true;
        } else if (x[i] == '2') {
          a[i] = b[i] = '1';
        } else {
          a[i] = b[i] = '0';
        }
      }
    }
    cout << a << "\n";
    cout << b << "\n";
  }

  return 0;
}

