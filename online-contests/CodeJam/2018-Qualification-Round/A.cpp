#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

inline i64 power(string &s)
{
  int f = 1LL, ans = 0LL;
  for (const char & si : s)
  {
    if (si == 'S') ans += f;
    else f <<= 1;
  }
  return ans;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    string s;
    int cnt = 0, L, R;
    i64 D;
    bool can = true;
    cin >> D >> s;
    while ((power(s) > D) && can)
    {
      bool move = false;
      for (int i=0; i<s.size()-1; ++i)
      {
        if (s[i] == 'C' && s[i+1] == 'S')
        {
          swap (s[i], s[i+1]);
          move = true;
          ++cnt;
          break;
        }
      }
      if (!move) can = false;
    }
    if (!can) cout << "IMPOSSIBLE" << endl;
    else cout << cnt << endl;
  }

  return 0;
}


