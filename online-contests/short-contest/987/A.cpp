#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;
using i64 = long long int;
using ss = pair<string, string>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  map <string, string> gem;
  map <string, bool> seen;

  gem["purple"] = "Power";
  gem["green"]  = "Time";
  gem["blue"]   = "Space";
  gem["orange"] = "Soul";
  gem["red"]    = "Reality";
  gem["yellow"] = "Mind";


  int n, ans;
  string s;

  cin >> n; 
  ans = gem.size() - n;
  while (n--) cin >> s, seen[s] = true;
  cout << ans << endl;
  for (const auto & ss : gem)
    if (!seen[ss.first])
      cout << ss.second << endl;

  return 0;
}


