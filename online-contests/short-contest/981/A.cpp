#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;

  cin >> s;

  int ans = 0, n = s.size();

  for (int l=0; l<n; ++l)
    for (int r=l+1; r<n; ++r)
    {
      bool pal = true;
      for (int k=l; k<=r; ++k)
      {
        int d = k-l;
        if (s[l+d] != s[r-d])
        {
          pal = false;
          break;
        }
      }
      if (!pal) ans = max(ans, r-l+1);
    }

  cout << ans << endl;


  return 0;
}


