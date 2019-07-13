#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n;
  string s, ans;
  cin >> n >> s;

  for (int i=0; i<n; ++i) {
    ans += s[i];
    while ((i+1<n) && s[i] == s[i+1]) ++i;
    if (i+1<n && s[i+1] != ans.back()) {
      ans += s[i+1];
      ++i;
    }
  }

  if (ans.size() & 1) ans.pop_back();
  cout << n - ans.size() << "\n" << ans << "\n";

  return 0;
}

