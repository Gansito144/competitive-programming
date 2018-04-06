#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  char mn = 'z'+1, mx = 'a'-1;
  vector <bool> c(26, false);
  vector <char> nxt(26, -1);
  int n, k;
  string s;

  cin >> n >> k;
  cin >> s;
  for (char si : s)
  {
    si = si - 'a';
    mn = min(mn, si);
    mx = max(mx, si);
    c[si] = true;
  }

  for (int i=0; i<26; ++i)
    for (int j=i+1; j<26; ++j)
      if (c[j])
      {
        nxt[i] = j;
        break;
      }

  if (k > n)
    s += string(k-n, mn+'a');
  else
  {
    string ans;
    for (int i=k-1; i>= 0; --i)
    {
      if (nxt[s[i]-'a'] != -1)
      {
        ans = s.substr(0, i);
        ans += nxt[s[i]-'a'] + 'a';
        ans += string(k-i-1, mn+'a');
        s = ans;
        break;
      }
    }

  }
  cout << s << endl;
  return 0;
}

