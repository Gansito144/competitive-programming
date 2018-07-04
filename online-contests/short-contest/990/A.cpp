#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 n, m, a, b;
  cin >> n >> m >> a >> b;
  i64 prv = (n / m) * m;
  i64 nxt = ((n+m-1LL) / m) * m;

  i64 ans = min((n - prv) * b, (nxt - n) * a);
  cout << ans << endl;

  return 0;
}


