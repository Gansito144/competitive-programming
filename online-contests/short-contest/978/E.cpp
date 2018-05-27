#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
using i64 = long long int;

int main ()
{
  
  int n, w, mn, mx, s = 0;
  cin >> n >> w;
  vector <int> b(n);

  mn = 0, mx = 0;
  for (int &bi : b)
  {
    cin >> bi;
    s += bi;
    mx = max(s, mx);
    mn = min(s, mn);
  }

  int R = w - mx;
  int L = abs(mn);

  // cout << L << " " << R << endl;
  cout << max(0, R-L+1) << endl;

  return 0;
}

