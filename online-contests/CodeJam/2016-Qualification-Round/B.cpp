#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main ()
{
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    char s[102], tmp[102];
    cin >> s;
    int L=0, R=strlen(s)-1, ans=0;
    while (true)
    {
      while (R >= 0 && s[R] == '+') --R;
      if (R < L) break;
      ++ans;
      if (s[0] != '-')
      {
        while (s[L] == '+') s[L++] = '-';
        L = 0;
      }
      else
      {
        for (int i=0; i<=R; ++i)
          tmp[R-i] = s[i];
        for (int i=0; i<=R; ++i)
          s[i] = tmp[i] == '+' ? '-' : '+';
      }
    }
    //cout << s << endl;
    cout << ans << endl;
  }
  return 0;
}

