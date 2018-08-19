#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using i64 = long long int;

inline bool is_vowel(const char &c) {
  return c=='a'||c=='e'||
    c=='i'||c=='o'||c=='u';
}

inline bool is_n(const char &c) {
  return c=='n';
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  bool isB = true;
  cin >> s;
  int n = int(s.size());
  for (int i=0; i<n; ++i) {
    if (is_vowel(s[i])) continue;
    if (is_n(s[i])) continue;
    //cout << i << " " << s[i] << " " << is_vowel(s[i+1]) << endl;
    if (i==(n-1) || !is_vowel(s[i+1])) {
      isB = false;
      break;
    }
  }

  cout << (isB?"YES":"NO") << endl;

  return 0;
}

