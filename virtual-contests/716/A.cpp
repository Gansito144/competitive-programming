#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n , c, ans = 0, pr, nw;
  cin >> n >> c;
  cin >> pr;
  ans = 1;
  for (int k=1; k<n; ++k)
  {
    cin >> nw;
    if (nw <= (pr + c))
      ++ans;
    else
      ans = 1;
    pr = nw;
  }
  cout << ans << endl;
  return 0;
}

