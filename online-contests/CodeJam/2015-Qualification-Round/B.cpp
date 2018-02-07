#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
  int pks[1003];
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    int n, ans = 123456789, mx = 0;
    cin >> n;
    for (int i=0; i<n; ++i)
    {
      cin >> pks[i];
      mx = max(mx, pks[i]);
    }
    for (int p=1; p<=mx; ++p)
    {
      int cnt = p;
      for (int pp=0; pp<n; ++pp)
      {
        cnt += (pks[pp]-1) / p;
      }
      ans = min(ans, cnt);
    } 
    cout << ans << endl;
  }
  return 0;
}
