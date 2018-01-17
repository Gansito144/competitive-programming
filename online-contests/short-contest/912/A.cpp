#include <iostream>

using namespace std;
using i64 = long long int;


int main ()
{
  i64 y, b;
  i64 yy, gg, bb;
  cin >> y >> b;
  cin >> yy >> gg >> bb;

  y -= yy*2LL;
  y -= gg;
  b -= bb*3LL;
  b -= gg;

  i64 ans = 0ll;
  if (b < 0LL) ans -= b;
  if (y < 0LL) ans -= y;
  cout << ans << endl;

  return 0;
}

