#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, coin, ans = 0;
  map <int, int> fr;

  cin >> n;

  while (n--)
  {
    cin >> coin;
    ans = max(ans, ++fr[coin]);
  }

  cout << ans << endl;

  return 0;
}


