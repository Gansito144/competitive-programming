#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  i64 r, c, k;

  cin >> r >> c >> k;

  if (k < r)
  {
    cout << (k+1LL) << " " << 1LL << endl;
  }
  else
  {
    k -= r;
    --c;
    i64 nr = r - (k/c);
    i64 nc;
    i64 pr = r % 2LL;
    i64 pnr = nr % 2LL;
    if (pr == pnr)
      nc = (k % c) + 2LL;
    else
      nc = c - (k % c) + 1LL;
    cout << nr << " " << nc << endl;
  }
  return 0;
}

