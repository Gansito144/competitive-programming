#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector <i64> sa(n+1, 0);
  vector <i64> A (n+1, 0);
  vector <i64> no(n+1, 0);

  for (int i=1; i<=n; ++i)
  {
    cin >> A[i];
    sa[i] = A[i] + sa[i-1];
  }

  int ti;
  for (int i=1; i<=n; ++i)
  {
    cin >> ti;
    no[i] = A[i]*ti + no[i-1];
  }

  i64 ans = 0;
  for (int R = k; R <= n; ++R)
  {
    ans = max(ans, no[n] - no[R] + sa[R] - sa[R-k] + no[R-k]);
  }

  cout << ans << endl;

  return 0;
}

