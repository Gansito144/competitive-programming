#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  if (n <= 2)
  {
    cout << 0 << endl;
    return 0;
  }

  vector <int> a(n);
  for (int &ai: a) cin >> ai;

  int ans = 123456789;

  for (int p0 = a[0]-1; p0 <= a[0]+1; ++p0)
  {
    for (int p1 = a[1]-1; p1 <=a[1]+1; ++p1)
    {
      int d = p1 - p0;
      int cnt = (p1 != a[1]) + (p0 != a[0]);
      bool can = true;
      //cout << p0 << ", " << p1 << " :d " << d;
      for (int p=2; p<n; ++p)
      {
        int na = p0 + d*p;
        //cout << " - " << na << " * " << a[p] << endl;
        if (abs(a[p] - na) > 1)
        {
          can = false;
          break;
        }
        cnt += na != a[p];
      }
      if (can) ans = min(ans, cnt);
    }
  }

  if (ans == 123456789) ans = -1; 
  cout << ans << endl;
  return 0;
}

