#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, op = 0, ans = 0, s;
  cin >> n;
  int N = n+1;
  int l=2, r=n, prv, nxt=1;
  while (--n) {
    prv = nxt;
    if (op) {nxt = l++;}
    else {nxt = r--;}
    s = nxt+prv;
    if (s >= N) s -= N;
    // cout << prv << "," << nxt << "," << s << endl;
    ans += s;
    op = 1 - op;
  }
  cout << ans << endl;
  return 0;
}


