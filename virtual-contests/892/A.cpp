#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 mx[2] = {-1LL, -1LL}, s = 0LL, a, b, n;

  cin >> n;
  for(i64 i=0LL; i<n; ++i)
  {
    cin >> a;
    s += a;
  }
  while (n--)
  {
    cin >>  b;
    if(mx[1] < b) swap(mx[1], b);
    if(mx[0] < b) swap(mx[0], b);
  }

  if(s <= (mx[0]+mx[1]))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

