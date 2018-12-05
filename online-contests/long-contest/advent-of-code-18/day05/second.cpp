#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main() {
  string str;
  int best = 123456789;
  cin >> str;
  for (char c='a'; c<='z'; ++c) {
    string s;
    for (const char &cc : str) 
      if (tolower(cc) != c)
        s += cc;
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
    if (s.size() < best)
      best = s.size();
  }
  cout << best << endl;
  return 0;
}

