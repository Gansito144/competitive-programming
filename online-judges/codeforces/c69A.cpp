#include <iostream>

using namespace std;

int main() {
  int a, b, c, tc;
  cin >> tc;
  a = b = c = 0;
  while (tc--) {
    int da, db, dc;
    cin >> da >> db >> dc;
    a += da; b += db; c += dc;
  }
  cout << ((!a && !b && !c) ? "YES" : "NO") << endl;
  return 0;
}

