#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  const int Z = 26;
  int n, k;
  string s;

  cin >> n >> k >> s;

  vector < queue<int> > p(Z);
  vector <bool> alive(n, true);

  for (int i=0; i<n; ++i)
  {
    p[s[i]-'a'].push(i);
  }

  bool some = false;
  while (k--)
  {
    for (int i=0; i<Z; ++i)
    {
      if (p[i].empty()) continue;
      alive[p[i].front()] = false;
      p[i].pop();
      break;
    }
  }

  for (int i=0; i<n; ++i)
    if (alive[i])
    {
      cout << s[i];
      some = true;
    }

  if (some) cout << endl;
  return 0;
}

