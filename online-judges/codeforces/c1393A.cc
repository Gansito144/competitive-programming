#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tcs;
  cin >> tcs;
  while (tcs--) {
    int n;
    cin >> n;
    n = (n+2) >> 1;
    cout << (n) << "\n";
  }
  return 0;
}

