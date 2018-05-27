#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

vector <int> day, s, d, c, p;

bool cmp (const int &a, const int &b)
{
  return d[a] < d[b];
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  day.assign(n, 0);
  s.assign(n, 0);
  c.assign(n, 0);
  p.assign(m, 0);
  d.assign(n, 0);
  vector <bool> seen(n, 0);
  for (int e=0; e<m; ++e)
  {
    cin >> s[e] >> d[e] >> c[e];
    --s[e]; --d[e];
    day[d[e]] = m + 1;
    seen[d[e]] = true; 
    p[e] = e;
  }

  sort(p.begin(), p.end(), cmp);

  bool can = true;

  for (int i=0; i<m; ++i)
  {
    int j = p[i];
    for (int x = s[j]; x<d[j] && c[j]; ++x)
    {
      if (!seen[x])
      {
        seen[x] = true;
        day[x] = j + 1;
        --c[j];
      }
    }
    if (c[j])
    {
      can = false;
      break;
    }
  }

  if (!can) cout << -1 << endl;
  else
  {
    for (int i=0; i<n; ++i)
      cout << day[i] << " ";
    cout << endl;
  }
  return 0;
}

