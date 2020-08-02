#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  int n;
  cin >> n;
  while (n--) {
    int x, y, z;
    cin >> x >> y >> z;
    // Generate
    int a = min(x, y);
    int b = min(x, z);
    int c = min(y, z);

    // Verify
    int xx = max(a, b);
    int yy = max(a, c);
    int zz = max(b, c);
    if (xx != x || y != yy || z != zz) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n" <<  a << " " <<  b << " " << c << "\n";
  }
  return 0;
}

