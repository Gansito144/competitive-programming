#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  const int N = 1000006;
  const i64 M = 1000000007LL;
  const int K = 9LL;
  vector <i64> ans(N);
  ans[1] = 1LL;
  for (int k=2; k<N; ++k) {
    ans[k] = ans[k-1] * K;
    ans[k] %= M;  
  }

  int tc, k;
  cin >> tc;
  while (tc--) {
    cin >> k;
    cout << (ans[k] * 10LL) % M << "\n";
  }
  return 0;
}

