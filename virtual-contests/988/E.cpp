#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
using i64 = long long int;

int test (string s, string p)
{
  int st = 0, n = s.size();
  int L = n-1;
  while (L >= 0 && s[L] != p[1]) --L;
  if (L < 0) return -1;
  for (int i=L+1; i<n; ++i)
  {
    swap(s[i], s[i-1]);
    ++st;
  }
  L = n-2;
  while (L >= 0 && s[L] != p[0]) --L;
  if (L < 0) return -1;
  for (int i=L+1; i<n-1; ++i)
  { 
    swap(s[i], s[i-1]);
    ++st;
  }
  int found = 0;
  if (s[0] == '0')
  {
    for (int i=0; i<n-2; ++i)
      found += s[i] == '0';
    if (found == n-3) return -1; 
  }
  return st + found;
}

int main ()
{
  string s;
  cin >> s;
  int ans = 123456789;
  if (s.size() < 2)
  {
    cout << "-1\n";
    return 0;
  }
  int sol = test(s, "00");
  if (sol >= 0) ans = min(ans, sol);
  sol = test(s, "25");
  if (sol >= 0) ans = min(ans, sol);
  sol = test(s, "50");
  if (sol >= 0) ans = min(ans, sol);
  sol = test(s, "75");
  if (sol >= 0) ans = min(ans, sol);
  if (ans == 123456789) ans = -1;
  cout << ans << endl;
  return 0;
}
