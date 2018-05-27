#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;

  cin >> n >> m;

  vector <i64> s(n+1, 0LL);

  for (int i=1; i<=n; ++i)
  {
    cin >> s[i];
    s[i] += s[i-1];
  } 

  i64 q;

  while (m--)
  {
    cin >> q;
    int id = (int) (lower_bound(s.begin(), s.end(), q) - s.begin());
    cout << id << " " << q - s[id-1] << endl;
  }

  return 0;
}

