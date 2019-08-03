#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  map<char, string> f;
  f['2'] = "2";
  f['3'] = "3";
  f['4'] = "322";
  f['5'] = "5";
  f['6'] = "53";
  f['7'] = "7";
  f['8'] = "7222";
  f['9'] = "7332";
  int n;
  string s, ans;
  cin >> n >> s;
  for (char &c : s)
    ans += f[c];
  sort(ans.begin(), ans.end(), greater<char>());
  cout << ans << endl;
  return 0;
}

