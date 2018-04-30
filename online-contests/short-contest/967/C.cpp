#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, ns, ne, v;
  cin >> n >> m >> ns >> ne >> v;

  vector <int> S(ns), E(ne);
  for (int &s: S) cin >> s;
  for (int &e: E) cin >> e;

  int q;
  cin >> q;

  int x1, y1, x2, y2;
  int ts, te, ans, lo, up;
  while (q--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 > y2)
    {
      swap (y1, y2);
    }
    ans = (x1 == x2) ? y2 - y1 : 1123456789;
    if (S.size())
    {
      lo = (int) (lower_bound (S.begin(), S.end(), y2) - S.begin());
      up = min(ns-1, lo + 4);
      lo = max(0 , lo - 4); 

      for (; lo<=up; ++lo)
      {
        ts =  abs(y1-S[lo]) + abs(x2-x1) + abs(y2-S[lo]);
        if (ts < ans) ans = ts;
      }
    }
    if (E.size())
    {
      lo = (int) (lower_bound (E.begin(), E.end(), y2) - E.begin());
      up = min(ne-1, lo + 4);
      lo = max(0, lo - 4);

      for (; lo<=up; ++lo)
      {
        te = abs(y1-E[lo]) + (abs(x2-x1)+v-1)/v + abs(y2-E[lo]);
        if (te < ans) ans = te;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
