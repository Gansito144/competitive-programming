#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;
using is = pair<size_t, string>;

int main() {
  string s, ans;
  set < is > seen;
  while (cin >> s && ans == "") {
    for (size_t i=0; i<s.size(); ++i) {
      auto tmp = s.substr(0,i) + s.substr(i+1);
      if (seen.find({i, tmp}) != seen.end()) {
        ans = tmp;
        break;
      }
      seen.insert({i, tmp});
    }
  }
  cout << ans << endl;
  return 0;
}

