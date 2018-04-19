#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  int C;

  cin >> C;
  while (C--)
  {
    i64 p, r, m , n;
    cin >> p >> r >> m >> n;
    ++m;
    if (m % p != 0LL) cout << "Sad eyes" << endl;
    else 
    {
      int cnt = 0;
      i64 tmp = m; 
      while (m % p == 0LL)
      {
        ++cnt;
        m /= p;
      }
      tmp = (n * (i64)cnt);
      if(tmp >= r) cout << "Lo lograste" << endl;
      else cout << "Sad eyes" << endl;
    }
  }
  return 0;
}

