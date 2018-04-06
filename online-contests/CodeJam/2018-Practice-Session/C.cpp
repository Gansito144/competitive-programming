#include <iostream>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc)
  {
    double D, Ki, Si, ans = -1.0;
    int N;
    cin >> D >> N;
    while (N--)
    {
      cin >> Ki >> Si;
      double T = (D-Ki)/Si;
      if (ans < 0)
        ans = D / T;
      ans = min(ans, D/T);
    }
    cout << fixed << setprecision(20) << "Case #" << tc << ": " << ans << endl;
  }

  return 0;
}
