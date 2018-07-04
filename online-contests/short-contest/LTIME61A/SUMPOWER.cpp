#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    i64 ans = 0;
    string s;
    cin >> N >> K >> s;
    vector <int> sa(N, 0);
    for (int i=1; i<N; ++i) {
      sa[i] = (s[i-1] != s[i]) + sa[i-1];
      // cout << i << " " << sa[i] << endl;
    }
    for (int i=K; i<N; ++i)
      ans += (sa[i] - sa[i-K]);
    cout << ans << endl;
  }

  return 0;
}


