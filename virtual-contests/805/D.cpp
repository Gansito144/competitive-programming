#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  i64 ans = 0, m = 1000000007, c = 0;
  int n;
  string s;
  cin >> s;
  n = s.size();
  for (int i=n-1; i>=0; --i) {
    if (s[i]=='a') {
      ans += c;
      ans %= m;
      c <<= 1;
      c %= m;  
    } else ++c;
  }
  cout << ans << endl;

  return 0;
}


