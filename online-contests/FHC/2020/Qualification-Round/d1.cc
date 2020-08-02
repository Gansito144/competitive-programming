#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using ll = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc) {
    int n, m;
    cin >> n >> m;
    vector <ll> cost(n, 0), in(n, 0), out(n, 0);
    multiset <ll> Q;
    Q.insert(0LL);
    cin >> cost[0];
    for (int i=1; i<n; ++i) {
      cin >> cost[i];
      int l = i - m - 1; 
      if (l >= 0) {
        if (out[l] != -1LL) {
          Q.erase( Q.find( out[l] ) );
        }
      }
      if (Q.size()) {
        in[i] = *Q.begin();
        if (cost[i]) {
          out[i] = in[i] + cost[i];
          Q.insert(out[i]);
        } else {
          out[i] = -1LL;
        }
      } else {
        in[i] = -1LL;
        out[i] = -1LL;
      }
    }
    cout << "Case #" << tc << ": " << in[n-1] << "\n";
  }

  return 0;
}

