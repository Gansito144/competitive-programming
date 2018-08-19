#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, ans;
  cin >> n;
  while (n--) {
    cin >> ans;
    ans -= 1 - (ans&1);
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
