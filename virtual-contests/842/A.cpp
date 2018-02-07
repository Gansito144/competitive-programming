#include <iostream>

using namespace std;
using i64 = long long int;

int main ()
{
  i64 l,r,x,y,k;
  cin >> l >> r >> x >> y >> k;
  while (x <= y)
  {
    i64 t = x * k;
    if ( t >= l && t <= r)
    {
      cout << "YES" << endl;
      return 0;
    }
    ++x;
  }
  cout << "NO" << endl;
  return 0;
}

