#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

constexpr int MX = 10004;
bitset <MX> is_prime;
bitset <MX> seen;
vector <int> primes;
map <int, map<int, int> > factors;

void prime_sieve() {
  is_prime.set();
  for (int p=2; p<MX; ++p) {
    if(is_prime.test(p)) {
      primes.push_back(p);
      for (int np = (p+p); np<MX; np += p) {
        is_prime.reset(np);
      }
    }
  } 
}

void factors_sieve() {
  for (int n=2; n<MX; ++n) {
    map <int, int> &f = factors[n];
    int a = n;
    for (const int &p: primes) {
      if (p > a) break;
      int cnt = 0;
      while (a % p == 0) {
        a /= p;
        ++cnt;
      }
      if (cnt) f[p] = cnt;
    }
  }
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // pre-comp
  prime_sieve();
  factors_sieve();

  // program
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, a;
    map <int, int> lcm;
    cin >> n >> m;
    seen.reset();
    while (n--) {
      cin >> a;
      seen.set(a);
      for (const auto &[p,e] : factors[a]) {
        lcm[p] = max(lcm[p], e);
      }
    }

    int mx = 0LL, ans = 1;
    for (int i=1; i<=m; ++i) {
      if (seen.test(i)) continue;
      int c = i;
      for (auto [p, e] : lcm) {
        if ((p > c) || (c == 1)) break;
        while (e--) {
          if (c % p) break;
          c /= p;
        }
      }
      if (c > mx) {
        ans = i;
        mx = c;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

