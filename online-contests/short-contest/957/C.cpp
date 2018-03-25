#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  i64 U;
  cin >> n >> U;
  vector <i64> E(n);
  for (int i=0; i<n; ++i) 
  {
    cin >> E[i];
  }

  int R = 0;
  double ans = 0.0;
  bool sol = false;
  
  for (int L=0; L<n; ++L)
  {
    R = max(R, L+2);
    if (R >= n)
      break;
    while ((R+1 < n) && (E[R+1] - E[L]) <= U)
    {
      ++R;
    }
    if (E[R] - E[L] > U)
    {
      continue;
    }
//    cout <<"["<<L<<","<<R<<"] = " << E[R]-E[L] << endl;
    sol = true;
    double tmp = E[R] - E[L] - (E[L+1] - E[L]);
    tmp = tmp / (double)(E[R]-E[L]);
    ans = max(ans, tmp);
  }

  if (!sol)
    cout << "-1\n";
  else
    cout << setprecision(20) << ans << endl;

  return 0;
}

