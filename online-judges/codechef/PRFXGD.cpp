#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    int k, x;
    map <char, int> fr;
    cin >> s >> k >> x;
    int ans = 0;
    for (int i=0; i<s.size(); ++i) {
      const char &c = s[i];
      if ((fr[c] + 1 > x)) {
        if (k > 0) {
          --k;
          continue;
        }
        break;
      }
      ++fr[c];
      ++ans;
    }
    cout << ans << "\n";
  }
  return 0;
}


