#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main() {
  string s, ans;
  cin >> s;
  while (true) {
    bool change = false;
    for (int i=1; i<s.size(); ++i) {
      if (tolower(s[i]) == tolower(s[i-1]) && s[i] != s[i-1]) {
        s = s.substr(0, i-1) + s.substr(i+1);
        change = true;
        break;
      }
    }
    if (!change) break;
  }
  cout << s.size() << endl;
  return 0;
}

