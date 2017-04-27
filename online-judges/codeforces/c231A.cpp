#include <iostream>

using namespace std;

int main() {
  int n, ans = 0, a, b, c;
  cin >> n;
  while(n--) {
    cin >> a >> b >> c;
    ans += (a+b+c > 1);
  }
  cout << ans << endl;
  return 0;
}

