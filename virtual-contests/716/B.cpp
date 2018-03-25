#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main ()
{
  const int Z = 26;
  int cnt[Z]={}, qms=0, i; 
  string s;
  cin >> s;

  if (s.size() < Z)
  {
    cout << -1 << endl;
    return 0;
  }

  for (i=1; i<Z; ++i)
    if(s[i-1] == '?') ++qms;
    else ++cnt[s[i-1]-'A'];

  bool can = false;
  for (--i; i<s.size(); ++i)
  {
    ++cnt[s[i]-'A'];
    if (i >= Z) --cnt[s[i-Z]-'A'];
    can = true;
    for (int k=0; k<Z; ++k)
      if (cnt[k] > 1)
      {
        can = false;
        break;
      }
    if (can)
    {
      for (int j=0; j<s.size(); ++j)
      {
        if (s[j] != '?') continue;
        if (j > i)
        {
          s[j] = 'A';
          continue;
        }
        if (j < i-Z)
        {
          s[j] = 'A';
          continue;
        }
        for (int k=0; k<Z; ++k)
          if (cnt[k] == 0)
          {
            s[j] = 'A' + k;
            ++cnt[k];
            break;
          }
      }
      break;
    }
  }

  if (can)
    cout << s << endl;
  else
    cout << -1 << endl;
  return 0;
}

