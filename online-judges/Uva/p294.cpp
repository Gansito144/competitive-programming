#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

const int MaxR = 31624; // Root of 10^9
bitset <MaxR> is_prime;
deque <int> primes;

void sieve() {
  is_prime.set();
  for(int p=2; p<MaxR; ++p) {
    if(is_prime[p]) {
      primes.push_back(p);
      for(int mult=p+p; mult<MaxR; mult+=p) {
        is_prime[mult] = false;
      }
    }
  }
}

void factorize(map<int,int> &cnt, int n) {
  int pr;
  for(int i=0; (i<primes.size()) && (n>1); ++i) {
    pr = primes[i];
    while(n%pr == 0) {
      n /= pr;
      cnt[pr]++;
    }
  }
}

int main() {
  int N, L, U, number, divisors, no_div;

  sieve();
  scanf("%d",&N);
  while(N--) {
    scanf("%d %d",&L,&U);
    divisors = number = 0;
    for(int num=L; num<=U; ++num) {
      map<int,int> pr;
      map<int,int>::iterator it;
      factorize(pr, num);
      no_div = 1;
      for(it=pr.begin(); it!=pr.end(); ++it) {
        no_div *= (1 + it->second);
      }
      if(no_div > divisors) {
        number = num;
        divisors = no_div;
      }
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n"\
        ,L,U,number,divisors);
  }
  return 0;
}


