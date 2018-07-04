#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  int n;
  cin >> n;
  vector <string> vs(n);

  for (string &s : vs) cin >> s;

  sort(vs.begin(), vs.end(), [=] (string a, string b) -> bool
      {return a.size() < b.size(); });
  
  bool can = true;
  for (int i=1; i<n; ++i)
  {
    if (vs[i].find(vs[i-1]) == string::npos)
    {
      can  = false;
      break;
    }
  }

  if (!can) cout << "NO\n";
  else
  {
    cout << "YES\n";
    for (const string & s : vs) cout << s << endl;
  }

  return 0;
}

