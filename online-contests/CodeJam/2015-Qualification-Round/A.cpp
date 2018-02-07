#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    string s;
    int n, ans = 0, cnt = 0;
    cin >> n >> s;
    for (int i=0; i<=n; ++i)
    {
      if (s[i] > '0')
      {
        int need = max(0, i-cnt);
        cnt += need + (int)(s[i]-'0');
        ans += need;
      }
    }
    cout << ans << endl;
  } 
  return 0;
}

