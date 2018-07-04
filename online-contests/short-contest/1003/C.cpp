#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  double sum = 0, ans = 0;
  int n, k;

  cin >> n >> k;
  vector <double> sa(n+1, 0.0);

  for (int i=1; i<=n; ++i) {
    cin >> sa[i];
    sa[i] += sa[i-1];
  }
  for (int i=0; i<=n; ++i) {
    for (int j=i+k; j<=n; ++j) {
      // cout << i << " " << j << " : " << sa[j] - sa[i] << endl;
      double kk = j - i;
      ans = max(ans, (sa[j] - sa[i]) / kk);
    }
  }
  cout << fixed << setprecision(30) << ans << endl;

  return 0;
}


