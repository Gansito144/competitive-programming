#include <iostream>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  i64 ans = 0LL, ones = 0LL;
  string number;

  cin >> number;

  for (int i=number.size()-1; i>=0; --i) {
    if (number[i] == '1') {
      ++ones;
      ans += ones;
    }
  }

  cout << ans << endl;
  return 0;
}

