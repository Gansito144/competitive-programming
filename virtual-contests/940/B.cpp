#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  i64 n, k, A, B, ans = 0LL;

  cin >> n >> k >> A >> B;

  if (n == 1LL)
  {
    cout << 0 << endl;
    return 0;
  }
  if (k == 1LL)
  {
    cout << (n-1LL)*A << endl;
    return 0;
  }
  while (n != 1LL)
  {
    if (n % k)
    {
      i64 tgt = max(1LL, (n/k)*k);
      ans += (n - tgt) * A;
      n = tgt;
    }
    else
    {
      i64 tgt = n / k;
      i64 cA = (n-tgt) * A;
      ans += min(B, cA);
      n = tgt;
    }
  }
  cout << ans << endl;
  return 0;
}

