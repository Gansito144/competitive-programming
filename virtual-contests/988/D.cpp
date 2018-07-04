#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using i64 = long long int;

inline bool test(int x)
{
  return __builtin_popcount(x) == 1;
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  i64 ai;
  cin >> n;
  vector <i64> v(n);
  set <i64> keys;
  for (i64 &vi : v )
  {
    cin >> vi;
    keys.insert(vi);
  }
  sort(v.begin(), v.end());

  // check 3's
  for (int i=1; i<n; ++i)
  {
    for (int k=0; k<31; ++k)
    {
      i64 prv = v[i] - (1LL << k);
      i64 nxt = v[i] + (1LL << k);
      if ((keys.find(prv) != keys.end())
          && (keys.find(nxt) != keys.end()))
      {
        cout << "3\n";
        cout << prv << " " << v[i] << " " << nxt << "\n";
        return 0;
      }
    }
  }

  // check 2's
  for (int i=1; i<n; ++i)
  {
    for (int k=0; k<31; ++k)
    {
      i64 prv = v[i] - (1LL << k);
      if (keys.find(prv) != keys.end())
      {
        cout << "2\n";
        cout << prv << " " << v[i] << "\n";
        return 0;
      }
    }
  }

  cout << "1\n" << v[0] << "\n";

  return 0;
}


