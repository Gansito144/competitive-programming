#include <iostream>
#include <algorithm>

using namespace std;

inline int match(int x)
{
  return ((x + (x&1)) >> 1);
}

int main ()
{
  int n, a, b;
  cin >> n >> a >> b;
  int cnt = 1;
  while ((a = match(a)) != (b = match(b)))
  {
    ++cnt;
    // cout << cnt << " " << a << " " << b << endl;
  }

  if (n == (1 << cnt))
    cout << "Final!" << endl;
  else
    cout << cnt << endl;
  return 0;
}

