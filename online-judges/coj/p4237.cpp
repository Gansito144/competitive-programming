#include <iostream>
#include <vector>

using namespace std;
using i64 = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  const int M = 1000006;
  i64 ans = 0LL, sum = 0LL;
  int N, prv, cur, nxt;
  cin >> N;
  vector <int> cnt(M, 0);
  for (int i=1; i<=N; ++i) {
    cin >> cur;
    sum += cur;
    ++cnt[cur];
    prv = cur-1;
    nxt = cur+1;
    ans -= (sum - cnt[prv]*prv - cnt[cur]*cur - cnt[nxt]*nxt);
    ans += (i - cnt[prv] - cnt[cur] - cnt[nxt]) * cur;
  }
  cout << ans << "\n";
  return 0;
}

