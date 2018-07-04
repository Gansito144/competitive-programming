#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  string s, ans;

  cin >> n >> s;

  for (int d=1; d<=n; ++d)
  {
    if (n % d) continue;
    ans = s.substr(0,d);
    reverse(ans.begin(), ans.end());
    ans = ans + s.substr(d);
    s = ans;
  }
  cout << ans << endl;
  return 0;
}

