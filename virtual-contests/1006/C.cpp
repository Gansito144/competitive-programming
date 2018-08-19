#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;

  cin >> n;
  vector <i64> v(n);

  for (i64 &vi : v) {
    cin >> vi;
  }

  i64 ans = 0;
  i64 sL = 0, sR = 0;
  for (int L=0, R=n-1; L<=R; --R) {
    sR += v[R];
    while (L<R && sL<sR) {
      sL += v[L];
      ++L;
    }
    //cout << L << " " << R << " = " << sL << " " << sR << endl;
    if (sL == sR)
      ans = max(ans, sL);
  }
  cout << ans << endl;
  return 0;
}
