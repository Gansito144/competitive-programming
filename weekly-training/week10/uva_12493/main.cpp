#include <iostream>
#include <bitset>
#include <queue>
#include <utility>
 
using namespace std;
 
const int kMaxN = (3 << 16);
bitset <kMaxN> is_prime;
deque <int> primes;
 
void sieve() {
  is_prime.set();
  for(int p=2; p<kMaxN; ++p) {
    if(is_prime.test(p)) {
      primes.push_back(p);
      for(int c=p+p; c<kMaxN; c+=p)
        is_prime.reset(c);
    }
  }
}
 
void primatiza(int n, deque<int> &dq) {
  for(int i=0; i<primes.size() && n>1; ++i) {
    if(n % primes[i] == 0) dq.push_back(primes[i]);
    while(n % primes[i] == 0) {
      n /= primes[i];
    }
  }
  if(n > 1) dq.push_back(n);
}
 
int main() {
  sieve();
  int n, ans;
  while(scanf("%d",&n)!= EOF) {
    deque<int> f;
    primatiza(n, f);
    ans = n;
    for(int i=0; i<f.size(); ++i) {
      int p = f[i];
      ans = (ans/p) * (p-1);
    }
    printf("%d\n",ans>>1);
  }
  return 0;
}
