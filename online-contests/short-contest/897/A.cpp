#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
  char s[1003];
  int n, m, l, r;
  char c1, c2;

  cin >> n >> m;
  cin >> s;
  while (m--)
  {
    cin >> l >> r >> c1 >> c2;
    replace(s+l-1, s+r, c1, c2);
  }
  cout << s << endl;
  return 0;
}

