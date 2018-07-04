#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  i64 sw, rp;
  int n;
  cin >> n >> sw >> rp;
  cin >> s;
  i64 zs = 0;
  string cs = s;
  replace(cs.begin(), cs.end(), '1', ' ');
  istringstream in(cs);
  while (in >> cs) ++zs;
  i64 ans = zs * rp;
  i64 cr = 0;
  int L = 0, R = n-1;

  while (L < n && s[L] == '1') ++L;
  while (R >=0 && s[R] == '1') --R;

  cs = "";
  for (int i=L; i<=R; ++i) cs += s[i] == '1' ? s[i] : ' ';
  istringstream on(cs);
  while (on >> cs) ++cr;
  ans = min(ans, rp + cr * sw);
  cout << ans << endl;
  return 0;
}


