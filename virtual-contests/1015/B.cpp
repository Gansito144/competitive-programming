#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  string a, b, ca, cb;

  cin >> n >> a >> b;

  ca = a; cb = b;
  sort(ca.begin(), ca.end());
  sort(cb.begin(), cb.end());
  if (ca != cb) {
    cout << -1 << endl;
  } else {
    vector <int> ans;
    for (int ib=0; ib<n; ++ib) {
      for (int ia=0; ia<n; ++ia) {
        if (a[ia] == b[ib]) {
          while (ia > ib) {
            swap (a[ia-1], a[ia]);
            ans.push_back(ia);
            --ia;
          }
          a[ib] = '-';
          break;
        }
      }
    }
    cout << ans.size() << endl;
    for (const int &vi : ans)
      cout << vi << " ";
    cout << endl;
  }

  return 0;
}

