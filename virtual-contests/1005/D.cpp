#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int ans = 0;
  string s;
  cin >> s;
  int n = s.size();
  vector <int> dp(n + 1, 0);
  for (int r=1; r<=n; ++r) {
    for (int l=r-2; l<=r; ++l) {
      if (l<=0 || (l!=r && s[l]=='0'))
        continue;
      int m = 0;
      for (int k=l; k<=r; ++k) m += s[k-1] - '0';
      m %= 3;
      dp[r] = max(dp[r], dp[l-1] + (m == 0));
    }
  }
  cout << dp[n] << endl;
  return 0;
}

