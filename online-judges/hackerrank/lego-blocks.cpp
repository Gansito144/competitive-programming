#include<iostream>

using namespace std;

typedef long long int i64;

const i64 Mod = 1000000007LL;
const int MaxN = 10010;
const i64 offset = 4;

i64 dp[MaxN], nc[MaxN], pow[MaxN];

inline i64 mod(i64 m) {
  return (m + Mod) % Mod;
}

i64 fast_pow(i64 base, int pot) {
  if(pot == 0) return 1LL;
  else {
    if(pot & 1) return mod(base * fast_pow(base, pot ^ 1));
    else {
      i64 r = fast_pow(base, pot >> 1);
      return mod(r * r);
    }
  }
}

int main() {
  int T, W, H;

  // Sieve
  dp[offset] = 1LL;
  for(int i=offset+1; i<MaxN; ++i) {
     for(int l=1; l<5; ++l)
       dp[i] = mod(dp[i] + dp[i-l]);
  }

  cin >> T;
  while(T--) {
    cin >> H >> W;
    for(int p=1; p<=W; ++p) pow[p] = fast_pow(dp[p + offset], H);
    for(int c = 1; c <= W; ++c) {
      nc[c] = pow[c];
      for(int d=1; d<c; d++) {
         i64 izq = pow[d];
         i64 der = nc[c-d];
         nc[c] = mod(nc[c] - mod(izq * der));
      }
    }
    cout << nc[W] << endl;
  }
  return 0;
}

