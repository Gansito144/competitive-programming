#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using i64 = long double;

int main ()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  i64 d, r, ans = 0, x, y, k;
  int n;
  cin >> r >> d;
  cin >> n;
  for (int i=1; i<=n; ++i)
  {
    cin >> x >> y >> k;
    i64 dd = sqrt(x*x+y*y);
    if (dd-k < r-d)
      continue;
    if(dd+k > r)
      continue;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}

