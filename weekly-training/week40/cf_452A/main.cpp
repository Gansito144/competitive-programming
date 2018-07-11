#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector <string> vs = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

  int n;
  string s;
  cin >> n >> s;
  for (const string &vi : vs) {
    if (vi.size() != s.size()) continue;
    bool match = true;
    for (int i=0; i<n; ++i) {
      if (s[i] == '.') continue;
      if (s[i] != vi[i]) {
        match = false;
        break;
      }
    }
    if (match) {
      cout << vi << endl;
      break;
    }
  }

  return 0;
}

