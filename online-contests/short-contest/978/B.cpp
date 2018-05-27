#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using i64 = long long int;

int main ()
{
  int n, cnt = 0, ans = 0;
  string s;

  cin >> n >> s;

  for (int i=0; i<n; ++i)
  {
    if (s[i] == 'x') ++cnt;
    else cnt = 0;
    if (cnt > 2) ++ans;
  }

  cout << ans << endl;

  return 0;
}

