#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main ()
{
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    int N;
    cin >> N;
    vector <i64> X(N), Y(N);
    for (i64 &x : X) cin >> x;
    for (i64 &y : Y) cin >> y;
    sort(X.begin(), X.end(), greater<i64>());
    sort(Y.begin(), Y.end(), less<i64>   ());
    i64 ans = 0;
    for (int i=0; i<N; ++i)
      ans += X[i] * Y[i];
    cout << ans << endl;
  }
  return 0;
}

