#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  int n, s, h, m, t;

  cin >> n >> s;

  vector <int> H(n), M(n);

  for (int i=0; i<n; ++i) cin >> H[i] >> M[i];

  bool ans = false;

  int ta = 0;
  ta = H[0]*60 + M[0];
  if (ta <= s)
  {
    for (int i=1; i<=n; ++i)
    {
      int tn = H[i]*60 + M[i];
      int tb = H[i-1]*60 + M[i-1];
      ta = tb + s*2 + 2;
      if (tn >= ta)
      {
        ta = tb + s + 1;
        ans = true;
        break;
      }
    }
    if (!ans) ta = H[n-1]*60 + M[n-1] + s + 1;
  } else ta = 0;
  cout << ta/60 << " " << ta%60 << endl;

  return 0;
}
