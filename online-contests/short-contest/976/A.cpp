#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  int n;
  string s, ans;

  cin >> n >> s;
  
  for (const char &c: s)
    if (c == '1')
    {
      ans += c;
      break;
    }
  for (const char &c: s)
    if (c == '0')
    {
      ans += c;
      if (ans.size() == 1)
        break;
    }

  cout << ans << endl;
  return 0;
}

