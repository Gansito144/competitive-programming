#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int i64;

inline i64 gauss(i64 n) {
  return (n&1LL) ? ((n+1LL)>>1)*(n) : (n>>1)*(n+1LL);
}

bool test(i64 &n, i64 d, i64 &k) {
  i64 g = gauss(k) * d;
  i64 gp = gauss(k-1) * d;
  //cout << gp << " " << g << endl;
  if(gp > n) return false;
  i64 rm = n-gp;
  if( rm % d) return false;
  if(rm <= (k-1LL)*d) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  i64 n, k, ans;

  cin >> n >> k;
  if(n < k || n < gauss(k) || k > 1234567LL) {
    cout << -1 << endl;
    return 0;
  }
  ans = -1;
  for(i64 d=1LL; d*d <= n ; ++d) {
    if(n % d) continue;
    if(test(n, d, k)) ans = max(ans, d);
    if(test(n, n/d, k)) ans = max(ans, n/d);
  }
  if(ans < 0) cout << ans << endl;
  else {
    i64 den = ans;
    i64 sum = 0LL, inc = 0LL;
    int N = k;
    for(int i=1; i<N; ++i) {
      inc += den;
      sum += inc;
      cout << inc << " ";
    }
    cout << n-sum << endl;
  }
  return 0;
}

