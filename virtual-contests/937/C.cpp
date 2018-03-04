#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using i64 = long long int;

int main ()
{
  i64 k, d;
  double t, on, off, ans, cook, eps=1e-9;
  cin >> k >> d >> t;
  on = k;
  off = (d - (k%d)) % d;
  cook = on + off / 2.0;
  // cout << on << " " << off << endl;
  // cout << on+off << " " << cook << endl;
  ans = floor(t / cook) * (on + off);
  t  -= floor(t / cook) * (cook);
  // cout << ans << " " << t << endl;
  if (t > eps)
  {
    ans += min(t, on);
    t   -= min(t, on); 
  }
  if (t > eps)
  {
    ans += min(t*2.0, off); 
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}

