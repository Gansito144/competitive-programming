#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int i64;

inline int lim(i64 N, i64 p) {
  int ret = 0;
  while(N >= p) {
    N /= p;
    ++ret;
  }
  return ret;
} 

int main() {
  i64 X, Y, L, R, XX, YY, ans = 0LL;
  set <i64> ul;
  set <i64> ::iterator it;

  cin >> X >> Y >> L >> R;
  XX = 1LL;
  int la = lim(R, X);
  for(int a=0; a<=la; ++a) {
    YY = 1LL;
    int lb = lim(R - XX, Y);
    for(int b=0; b<=lb; ++b) {
      ul.insert(XX+YY);
      YY *= Y;
    }
    XX *= X;
  }
  for(it = ul.begin(); it != ul.end(); ++it) {
    if(*it < L) continue;
    if(*it > R) break;
    ans = max(*it-L, ans);
    L = *it+1LL;
    if(L > R) break;
  }

  ans = max(ans, R-L+1LL);

  cout << ans << endl;
  return 0;
}


