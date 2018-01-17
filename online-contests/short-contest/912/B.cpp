#include <iostream>

using namespace std;
using i64 = long long int;

int main ()
{
  i64 N, K;
  cin >> N >> K;
  if (K > 1LL)
  {
    bool chg = false;
    for (int k = 62; k >=0; --k)
    {
      if (chg) N |= (1LL << k);
      chg = chg || (N>>k & 1LL);
    }
  }
  cout << N << endl;
  return 0;
}

