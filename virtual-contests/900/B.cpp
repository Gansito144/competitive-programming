#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main ()
{
  int a, b, c;
  unordered_set <int> rem;
  cin >> a >> b >> c;
  a %= b;
  int cnt = 0;
  while (rem.find(a) == rem.end())
  {
    rem.insert(a);
    ++cnt;
    a *= 10;
    int cc = a / b;
    if (cc == c)
    {
      cout << cnt << endl;
      return 0;
    }
    a %= b;
  }
  cout << -1 << endl;
  return 0;
}

