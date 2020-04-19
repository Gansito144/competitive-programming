#include<iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

using namespace std;
using ii = pair <int,int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int n, mx = 0, mn;
    cin >> n;
    vector <int> v(n);

    for (int &vi : v) {
      cin >> vi;
      mx = max(mx, vi);
    }
    set <ii> ans;
    mn = n - mx;

    // Try max right
    vector <bool> sL(mn + 1, false), sR(mx + 1, false);
    bool can = true;
    for (int i=0; i<n; ++i) {
      if (i < mn) {
        if (v[i] > mn) {
          can = false;
          break; 
        } else if (sL[v[i]]) {
          can = false;
          break;
        }
        sL[v[i]] = true;
      } else {
        if (sR[v[i]]) {
          can = false;
          break;
        }
        sR[v[i]] = true;
      }
    }
    if (can && mn) ans.insert({mn, mx});

    // Try max left
    vector <bool> SL(mx + 1, false), SR(mn + 1, false);
    can = true;
    for (int i=0; i<n; ++i) {
      if (i >= mx) {
        if (v[i] > mn) {
          can = false;
          break; 
        } else if (SR[v[i]]) {
          can = false;
          break;
        }
        SR[v[i]] = true;
      } else {
        if (SL[v[i]]) {
          can = false;
          break;
        }
        SL[v[i]] = true;
      }
    }
    if (can && mn) ans.insert({mx, mn});
    cout << ans.size() << "\n";
    for (const auto & x : ans) cout << x.first << " " << x.second << "\n"; 
  }
  return 0;
}


