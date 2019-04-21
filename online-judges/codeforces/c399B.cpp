#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  string s;
  int N;
  i64 ans = 0;

  cin >> N >> s;
  for (int p=0; p<N; ++p) {
    if (s[p] == 'B')
      ans += 1LL << p;
  }

  cout << ans << endl;
  return 0;
}

