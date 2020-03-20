#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using i64 = long long int;

const i64 mod = 1000000007LL;
const int MAXN = 100005;
vector <i64> f(MAXN);
vector <i64> rf(MAXN);

void sieve () {
  f[0] = 1LL;
  for(i64 N = 1LL; N < MAXN; ++N) {
    f[N] = N * f[N-1];
    f[N] %= mod;
  }
}

i64 fast_pow(i64 b, i64 e) {
  if (e == 0) return 1LL;
  if (e & 1LL) return (b * fast_pow(b, e - 1LL)) % mod;
  i64 m = fast_pow(b, e >> 1);
  return (m * m) % mod; 
}

i64 comb(int N, int k) {
  if (k == 0 || k == N) return 1LL;
  return (f[N] * fast_pow((f[k] * f[N-k]) % mod, mod - 2LL)) % mod;
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  sieve();

  int tcs;
  cin >> tcs;
  for (int tc=0; tc<tcs; tc++) {
    string A, B;
    int N, oA=0, oB=0, diff;
    cin >> N >> A >> B;
    for (const char c : A) oA += (c == '1');
    for (const char c : B) oB += (c == '1');
    if (oA > oB) swap(oA, oB);
    i64 ans = 0LL;
    diff = oB - oA;
    int lft = N - oB;
    for (int k=diff; k<=N && oA>=0 && lft>=0; k+=2, oA--, lft--) {
      ans += comb(N, k);
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}

