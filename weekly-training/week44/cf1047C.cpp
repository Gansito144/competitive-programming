#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int gcd(int a, int b) {
  while (b) {
    a %= b;
    b ^= a;
    a ^= b;
    b ^= a;
  }
  return a;
}

const int MAXN = 150000001;
std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
  for (int i = 2; i < n; ++i) {
    if (!is_composite[i]) prime.push_back (i);
    for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int n, mx = 0, g = 0;
  cin >> n;

  vector <int> v(n);
  
  for (int &vi : v) {
    cin >> vi;
    mx = max(mx, vi);
    g = gcd(vi, g);
  }

  mx /= g;
  mx = int(sqrt(mx));
  sieve(++mx);
  for (int &vi : v) vi /= g;
  map <int, int> f;
  for (int &vi : v) {
    for (const int &p : prime) {
      if (p > vi) break;
      if (vi % p) continue;
      while(vi % p == 0) vi /= p;
      ++f[p];
    }
    if (vi > 1) ++f[vi];
  }
  mx = 0; 
  for (const auto it : f) mx = max(mx, it.second);
  mx = (mx == 0) ? -1 : n - mx;
  cout << mx << endl;

  return 0;
}
