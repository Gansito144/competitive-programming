#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n, ans = 0;
  string a, b;

  cin >> n >> a >> b;
  int nn = (n+1) / 2;
  for (int i=0; i<nn; ++i) {
    int op = n-i-1;
    if (op == i)
      ans += a[i] != b[i];
    else {
      if (b[i] == b[op])
        ans += a[i] != a[op];
      else {
        if (a[i] == b[i])
          b[i] = '-';
        else if (a[i] == b[op])
         b[op] = '-';
        else
         ++ans;
        ans += a[op] != b[op] && a[op] != b[i];
      }
    }
    // cout << i << " " << ans << endl;
  }

  cout << ans << endl;

  return 0;
}
