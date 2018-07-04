#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>

#define F first
#define S second

using namespace std;
using i64 = long long int;
using vi = vector <int>;
using vvi = vector <vi>;
using ii = pair <int,int>;
using vii = vector <ii>;

i64 sort(vvi &G, int n, const vi &val, vii &lim) {
  if (val[n]) {
    lim[n] = {val[n], val[n]};
    return 0;
  } else {
    int l = G[n][0], r = G[n][1];
    i64 L = sort(G, l, val, lim);
    if (L < 0) return L;
    i64 R = sort(G, r, val, lim);
    if (R < 0) return R;
    if (lim[l].S < lim[r].F)
    {
      lim[n] = {lim[l].F , lim[r].S};
      return L + R;
    } else {
      if (lim[l].F > lim[r].S) {
        lim[n] = {lim[r].F, lim[l].S};
        return L + R + 1; 
      } else return -1;
    }
  }
}


int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int N, l, r;
    cin >> N;
    vi values(N, 0);
    vii lim(N, {INT_MAX, INT_MIN});
    vvi G(N);
    for (int i=0; i<N; ++i)
    {
      cin >> l >> r;
      if (l == -1) values[i] = r;
      else {
        --l; --r;
        G[i].push_back(l);
        G[i].push_back(r);
      }
    }
    i64 ans = sort(G, 0, values, lim);
    cout << ans << endl;
  }

  return 0;
}


