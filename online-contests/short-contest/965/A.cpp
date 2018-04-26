#include <iostream>

using namespace std;
using i64 = long long int;

int main ()
{
  i64 k, n, s, p;
  
  cin >> k >> n >> s >> p;

  i64 A = (n+s-1LL) / s;
  i64 B = k * A;
  i64 ans = (B+p-1LL) / p;

  cout << ans << endl;
  return 0;
}

