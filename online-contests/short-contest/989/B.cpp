#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  int n, p;
  string s, ans = "No";
  bool op = false;
  cin >> n >> p;
  cin >> s;
  for (int i=0; i<p; ++i)
  {
    int pos = 0;
    int os = 0, zs = 0, ds = 0;
    char x = -1;
    for (int j=i; j<n; j += p)
    {
      os += s[j] == '1';
      zs += s[j] == '0';
      ds += s[j] == '.';
    }

    if ((os && zs) || (ds > 1) || (ds && (os || zs)))
    {
      ans = s;
      bool flag = true;
      for (int j=i; j<n; j += p)
      {
        if (s[j] == '.')
        {
          if (os) ans[j] = '0';
          else if (zs) ans[j] = '1';
          else
          {
            if (flag)
            {
              ans[j] = '0';
              flag = false;
            } else ans[j] = '1';
          }
        }
      }
      replace(ans.begin(), ans.end(), '.', '1');
    }
  }
  cout << ans << endl;
  return 0;
}


