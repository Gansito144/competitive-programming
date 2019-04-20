#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  i64 N , ans = 0;

  cin >> N;
  vector <i64> v(N);

  for(i64 &vi: v) cin >> vi;
  sort(v.begin(), v.end());

  for (i64 p=1LL; p<=N; ++p)
    ans += abs(p - v[p-1LL]);

  cout << ans << endl;

  return 0;
}


