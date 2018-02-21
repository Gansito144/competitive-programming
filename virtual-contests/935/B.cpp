#include <iostream>
#include <string>

using namespace std;

int main ()
{
  int sd  = -1, n;
  int x = 0, y = 0, ans = 0;

  string st;
  cin >> n >> st;
  
  if (st[0] == 'U') ++y, sd = 0;
  else ++x, sd = 1;

  for (int i=1; i<n; ++i)
  {
    if (st[i] == 'U') ++y;
    else ++x;
    if (x == y)
      continue;
    int ns = x > y;
    ans += (ns != sd);
    sd = ns;
  }
  cout << ans << endl;
  return 0;
}

