#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
  int n;
  string s, ans;
  cin >> n >> s;
  s += s.back();
  for (int i=1; i<=n; ++i)
  {
    if (s[i] != s[i-1])
    {
      ans += "D";
      ++i;
    }
    else ans += s[i];
  }
  cout << ans.size() << endl; 
  return 0;
}


