#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, ans = 0;
  cin >> n;
  vector <int> v(n);
  for (int i=0; i<n; ++i) cin >> v[i];
  for (int i=0; i<n; ++i) {
    int L = i, R = i, prv = v[i];
    while (R<n  && v[R]<=prv) {prv = v[R]; ++R;}
    prv = v[i];
    while (L>=0 && v[L]<=prv) {prv = v[L]; --L;}
    --R; ++L;
    int wide = R-L+1;
    ans = max(ans, wide);
  }
  cout << ans << endl;
  return 0;
}


