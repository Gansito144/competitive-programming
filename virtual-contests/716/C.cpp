#include <iostream>
#include <cstdio>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  i64 n, x = 2LL;

  cin >> n;
  for (int k=1; k<=n; ++k)
  {
    i64 K = (i64)(k);
    i64 tgt = K * (K+1LL) * (K+1LL);
    i64 steps = (tgt - x);
    cout << steps << endl;
    x = K;
  }
  return 0;
}

