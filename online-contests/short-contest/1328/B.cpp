#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  for(int tc=0; tc <T; ++tc) {
    int n, k, cnt=1, tot = 0;
    cin >> n >> k;
    string ans(n, 'a');
    while (tot+cnt < k) {
      tot += cnt;
      ++cnt;
    }
    ans[n - cnt - 1] = 'b';
    k -=  tot;
    ans[n - k] = 'b';
    cout << ans << "\n";
  }

  return 0;
}

