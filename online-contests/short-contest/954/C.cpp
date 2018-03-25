#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x=-1, y=-1, mx=-1;
  cin >> n;
  vector <int> pt(n);
  for (int &p : pt)
  {
    cin >> p;
    mx = max(mx, p);
  }

  for (int i=1; i<n; ++i)
  {
    int d = abs(pt[i] - pt[i-1]);
    if (d==0 || d>1)
    {
      if (!d || (y != -1 && y != d))
      {
        cout << "NO" << endl;
        return 0;
      }
      y = d;
    }
  }
  if (y != -1)
  {
    for (int i=1; i<n; ++i)
    {
      int d = abs(pt[i] - pt[i-1]);
      if (d == 1)
      {
        int pr = (pt[i-1] - 1) / y;
        int ar = (pt[i] - 1) / y;
        if (pr != ar)
        {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  if (y == -1) y = mx;
  x = (mx - 1) / y + 1;
  cout << "YES" << endl << x << " " << y << endl;
  return 0;
}

