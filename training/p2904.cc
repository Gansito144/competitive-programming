#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, cnt = 0;
  cin >> N;
  vector <i64> s(2*N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> s[ i ];
    s[i + N] = s[ i ];
  }
  for (int i = 1; i < s.size(); ++i) {
    s[i] += s[i - 1];
     // cout << i << " - " << s[i] << endl;
  }
  int M = 1;
  for (int L = 1, R = N; L <= N; ++L, ++R) {
    while (M <= L || ((s[M] - s[L-1]) < (s[R] - s[M]))) ++M;
    if ((s[M] - s[L-1]) == (s[R] - s[M])) {
      ++cnt;
      // cout << cnt << " :: " <<  L << " " << M << " " << R << " " << endl;
    }
  }
  cout << ((cnt > 2) ? "Y" : "N") << endl;
  return 0;
}

