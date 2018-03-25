#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector <i64> required(n, 0);
  vector <i64> above(n, 0);

  i64 H = 0;
  for (int i=0; i<n; ++i)
  {
    cin >> above[i];
    if (above[i] + 1 > H)
      H = above[i] + 1LL;
    required[i] = H;
  }
  for (int i=n-2; i>=0; --i)
  {
    required[i] = max(required[i], required[i+1]-1LL);
  }
  i64 ans = 0LL;
  for (int i=0; i<n; ++i)
  {
    //cout << required[i] << " " << above[i] << " " << endl;
    ans += required[i] - (above[i] + 1LL);
  }
  cout << ans << endl;
  return 0;
}


