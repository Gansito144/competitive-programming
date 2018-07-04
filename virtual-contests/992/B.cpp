#include <iostream>
#include <utility>
#include <set>

using namespace std;
using i64 = long long int;
using ii = pair <int,int>;

inline i64 Gcd(i64 a, i64 b)
{
  while (b > 0LL)
  {
    a %= b;
    b ^= a;
    a ^= b;
    b ^= a;
  }
  return a;
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 GCD, LCM, l, r;

  cin >> l >> r >> GCD >> LCM;

  set <ii> ans;
  set <i64> div;
  i64 a, b, gcd, lcm;

  for (i64 d=1LL; d*d<=LCM; ++d)
  {
    if (LCM % d) continue;
    div.insert(LCM / d);
    div.insert( d );
  }

  for (const i64 &a : div)
    for (const i64 &b : div)
    {
      gcd = Gcd (a, b);
      lcm = (a * b) / gcd;
      if (gcd != GCD || lcm != LCM) continue;  
      if (a > r || b > r) continue;
      if (a < l || b < l) continue;
      ans.insert({a, b});
    }
  cout << ans.size() << endl;
  return 0;
}

