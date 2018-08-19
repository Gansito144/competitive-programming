#include <iostream>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  i64 n, h;
  int q;
  cin >> n >> q;
  h = (n*n + 1LL) >> 1;
  while (q--) {
    i64 x, y, ans;
    cin >> x >> y;
    ans = (x-1LL) * n + y;
    ans = (ans + 1LL) >> 1;
    //cout << "T: " << ans << endl;
    if ((x+y) & 1) {
      ans += h;
    }
    cout << ans << endl;
  } 
  return 0;
}

