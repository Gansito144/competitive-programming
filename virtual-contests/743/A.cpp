#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b, n;
  string s;
  cin >> n >> a >> b >> s;
  --a; --b;
  int gap = 2*n;
  for (int L=0, R = 1; L<n; ++L) {
    while (R < n && s[L] == s[R]) R++;
    gap = min(gap, R-L);
  }
  int ans = s[a] == s[b] ? 0 : gap; 
  cout << ans << endl;
  return 0;
}

