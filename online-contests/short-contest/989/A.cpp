#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  string s;
  bool can = false;
  cin >> s;

  for (int i=2; i<s.size(); ++i)
  {
    string tmp;
    tmp += s[i];
    tmp += s[i-1];
    tmp += s[i-2];
    sort(tmp.begin(), tmp.end());
    can = can || (tmp == "ABC");
  }

  cout << (can?"Yes":"No") << endl;

  return 0;
}

