#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
  int n;
  string s;
  map <string, int> cnt;

  cin >> n >> s;

  for (int i=1; i<n; ++i)
    ++cnt[string(1, s[i-1]) + s[i]];

  int ans = 0; s = "";
  for (const auto &si : cnt)
    if (si.second > ans)
    {
      tie(s, ans) = si;
    }

  cout << s << endl;

  return 0;
}

