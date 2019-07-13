#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>

using namespace std;
using i64 = long long int;

const int M = 1000006;
bitset <M> ip;
vector <int> p;

void sieve() {
  ip.set();
  for (int i=2; i<M; ++i) {
    if (ip.test(i)) {
      p.push_back(i);
      for (int j=i; j<M; j+=i)
        ip.reset(j);
    }
  }
}

i64 pot (i64 b, int e) {
  if (e == 0) return 1LL;
  i64 h = pot(b, e >> 1);
  return h * h * (e&1?b:1LL);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();

  int T;

  cin >> T;
  while (T--) {
    int d;
    cin >> d;
    map <int, int> f;
    vector <int> dd (d);
    for (int &di : dd) {
      cin >> di;
      int D = di;
      for (int j=0; j<p.size() && D > 1 && p[j] <= D; ++j) {
        if (D % p[j]) continue;
        int cnt = 0;
        while (D % p[j] == 0) {
          ++cnt;
          D /= p[j];
        }
        if (!f.count(p[j])) f[p[j]] = cnt;
        f[p[j]] = max(cnt, f[p[j]]);
      }
    }
    // Check
    if (f.size() == 1) ++(f.begin()->second);
    int nd = 1;
    i64 ans = 1LL;
    for (const auto &x : f) {
      nd *= (x.second + 1);
      ans *= pot(x.first, x.second);
    }
    nd -= 2;
    if (nd != d) ans = -1LL;
    for (const int &di : dd) if (di == ans) {
      ans = -1;
      break;
    }
    cout << ans << "\n";
  }
  return 0;
}

