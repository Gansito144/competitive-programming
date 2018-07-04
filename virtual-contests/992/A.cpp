#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, x;
  set <int> s;

  cin >> n;

  while (n--)
  {
    cin >> x;
    if (x) s.insert(x);
  }

  cout << s.size() << endl;
  return 0;
}

