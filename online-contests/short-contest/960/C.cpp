#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  int x;
  i64 d;
  vector <i64> ans;
  i64 nxt = 1;
  cin >> x >> d;
  while (x > 1 && ans.size() < 10000)
  {
    int k;
    for (k=30; k>=0; --k)
    {
      if ((x >> k) & 1)
      {
        break;
      }
    }
    for (int i=0; i<k; ++i)
      ans.push_back(nxt);
    nxt += ( d + 1LL);
    x -= (1<<k);
    ++x;
  }
  if (ans.size() < 10000)
  {
    ans.push_back(nxt);
    cout << ans.size() << endl;
    for (const i64 &ai : ans ) cout << ai << " ";
    cout << endl;
  } else cout << -1 << endl;
  return 0;
}
