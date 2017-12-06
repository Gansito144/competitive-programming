#include <iostream>

using namespace std;
using i64 = long long int;

inline i64 make_pal(i64 n, const i64 &m)
{
  i64 ret = 0, p = n;
  while (n)
  {
    ret = (ret*10LL + n % 10LL);
    ret %= m;
    n /= 10LL;
    p *= 10LL;
  }
  ret = (ret + p) % m;
  return ret;
}

int main ()
{
  i64 ans = 0, n, m;
  cin >> n >> m;
  while (n > 0)
  {
    ans = (ans + make_pal(n--, m)) % m;
  }
  cout << ans << endl;
  return 0;
}

