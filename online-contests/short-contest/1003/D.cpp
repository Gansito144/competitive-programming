#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  const int N = 31; 
  int n, q, p;

  cin >> n >> q;
  vector <int> fr(N, 0);

  while (n--) {
    cin >> p;
    for (int b=0; b<N; ++b)
      if ((p>>b) & 1) {
        ++fr[b];
        break;
      }
  }

  while (q--) {
    n = 0;
    cin >> p;
    for (int b=N-1; b>=0; --b) {
      if (!fr[b]) continue;
      int tmp = min(fr[b], p/(1<<b));
      n += tmp;
      p -= tmp * (1<<b);
    }
    if (p) n = -1;
    cout << n << endl;
  }

  return 0;
}


