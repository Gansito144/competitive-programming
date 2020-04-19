#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;
constexpr int N = 32000;

bitset <N> is_prime;
vector <int> primes;

void sieve() {
  is_prime.set();
  for(int p=2; p<N; ++p) {
    if (is_prime.test(p)) {
      primes.push_back(p);
      for (int np=p<<1; np<N; np+=p)
        is_prime.reset(np);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  sieve();

  int tc;
  cin >> tc;
  while(tc--) {
    int x, k;
    string can = "1\n";
    cin >> x >> k;
    if (k > 1) {
      for (const int &p : primes) {
        if (k == 0) break;
        if (x < p) break;
        while(k && (x%p == 0)) {
          k--;
          x /= p;
        }
      }
      if (x > primes.back()) --k;
      if (k > 0) can = "0\n";
    }
    cout << can;
  }
  return 0;
}


