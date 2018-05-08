#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using i64 = long long int;

int main ()
{
  string s;
  int os = 0, ds = 0;

  cin >> s;
  for (const char &c: s)
  {
    if (c == 'o')
      ++os;
    else
      ++ds;
  }
  if (os == 0) cout << "YES" << endl;
  else cout << ((ds % os == 0) ? "YES" : "NO") << endl;
  return 0;
}


