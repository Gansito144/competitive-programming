#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    map <char, int> m;
    int n;
    string s;
    cin >> n;
    for (int i=0; i<n; ++i) {
      cin  >> s;
      for (const char &c : s) m[c]++;
    }
    bool can = true;
    for (const auto &it : m) {
      if (it.second % n) {
        can = false;
        break;
      }
    }
    cout << (can ? "YES\n" : "NO\n") ; 
  }
  return 0;
}

