#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main() {
  string s;
  map <char, int> fr;
  cin >> s;
  for(char c: s) ++fr[c];
  long long int ans  = 0LL;
  for(const auto p : fr) {
    long long int x = p.second;
    ans += x*x;
  }
  cout << ans << endl;
  return 0;
}

