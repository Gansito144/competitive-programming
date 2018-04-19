#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n, a, p, aij;
    cin >> a >> p;

    vector <vector <int>> can(p, vector <int> (2, 0));
  
    while (a--)
    {
      for (int i=0; i<p; ++i)
      {
        cin >> aij;
        can[i][aij] = true;
      }
    }
  
    int c, ans = 0;

    cin >> c;
    while (c--)
    {
      int sol = 1;
      for (int i=0; i<p; ++i)
      {
        cin >> aij;
        sol *= (int)can[i][aij];
      }
      ans += sol;
    }
    cout << ans << endl;
  }
  return 0;
}

