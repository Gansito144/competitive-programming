#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int i64;

const int kCows = 112345;

i64 cb[kCows]; 
int n, k;

i64 f(i64 s) {
  if(s < cb[n-1]) return 0LL;
  int nk = 0;
  int L = 0, R = n-1;
  while(true) {
    if(L > R) break;
    if(L == R) {
      ++nk;
      break;
    } else {
      if(cb[R] + cb[L] <= s) {
        --R;
        ++L;
        ++nk;
      } else {
        ++nk;
        --R;
      }
    }
  }
  return (nk <= k);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for(int i=0; i<n; ++i) {
    cin >> cb[i];
  }

  i64 s = (1LL<<60) - 1LL;
  for(int b=59; b>=0; --b) {
    s ^= f(s^(1LL<<b)) << b;
  }
  cout << s << endl;
  return 0;
}

