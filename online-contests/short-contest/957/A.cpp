#include <iostream>
#include <string>

using namespace std;

int main ()
{
  int n;
  string s;
  cin >> n >> s;
  bool twoL = false;
  bool twoQ = false;
  bool between = false;
  for (int i=1; i<n; ++i)
  {
    if (s[i] == s[i-1])
    {
      if(s[i] == '?')
        twoQ = true;
      else
        twoL = true;
    }
    if (i != n-1 && s[i] == '?' && s[i-1] == s[i+1])
    {
      between = true;
    }
  }
  bool ini = s[0] == '?';
  bool fin = s[n-1] == '?';
  if (!twoL && (between || twoQ || ini || fin))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

