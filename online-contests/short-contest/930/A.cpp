#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

inline i64 g(i64 x)
{
  return (x&1LL)
    ? ((x+1LL)>>1)*(x)
    : ((x+1LL)*(x>>1));
}

int main ()
{
  i64 a, b;
  cin >> a >> b;
  if( a > b)
    swap(a, b);
  i64 m = (b-a);
  a = (m+1LL)>>1;
  b = (m) >> 1;
  m = g(a) + g(b);
  cout << m << endl;
  return 0;
}
