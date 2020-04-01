#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  for(int tc=0; tc<T; ++tc) {
    int n;
    cin >> n;
    vector <int> v(n), a(n);
    for (int &vi: v) {
      cin >> vi;
    }
    int mx = 1;
    bool can = false;
    a[0] = 1;
    for (int i=1; i<n; ++i) {
      if (v[i] == v[i-1]) {
        a[i] = a[i-1];
        can = true;
      }
      else a[i] = (a[i-1] == 1) ? 2 : 1;
      mx = max(mx, a[i]);
    }
    if(v[n-1] != v[0] && a[n-1] == a[0]) {
      if (!can) a[n-1] = 3;
      else {
        for (int i=1; i<n; ++i) {
          if (v[i] == v[i-1]) {
            if (can) {
              a[i] = (a[i-1] == 1) ? 2 : 1;
              can = false;
              continue;
            }
            a[i] = a[i-1];
          } else {
            a[i] = (a[i-1] == 1) ? 2 : 1;
          }
        }
      }
    }
    mx = max(mx, a[n-1]);
    cout << mx << "\n";
    for (const int &ai: a) cout << ai << " ";
    cout << "\n";
  }

  return 0;
}

