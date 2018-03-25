#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
  int n, ans;
  string s;

  cin >> n >> s;
  ans = n;
  for (int j = n; j>0; --j)
  {
    if(j%2 == 0)
    {
      int sz = j>>1;
      string a = s.substr(0, sz);
      string b = s.substr(sz, sz);
      if (a != b) continue;
      ans = min((n - j) + (sz) + 1, ans);
    }
  }
  cout << ans << endl;

  return 0;
}

