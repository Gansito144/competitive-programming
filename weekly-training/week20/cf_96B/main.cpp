#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;
using i64 = long long int;

const int kMaxPot = 20;

i64 buildMaxLuckyNumber(int fours, int sevens) {
  i64 ret = 0LL;
  for(int i=0; i<sevens; ++i) {
    ret = ret * 10LL + 7LL;
  }
  for(int i=0; i<fours; ++i) {
    ret = ret * 10LL + 4LL;
  }
  return ret;
}

int main() {
  // Get desired target
  i64 target;
  cin >> target;
  // Boundaries
  int fours = 0, sevens = 0;
  i64 ans;
  while( (ans=buildMaxLuckyNumber(fours, sevens)) < target) {
    ++fours;
    ++sevens;
  }
  // Build Solution
  char n[22];
  sprintf(n,"%I64d",ans);
  int N = fours + sevens;
  for(int i=0; i<N; ++i) {
    for(int j=i+1; j<N; ++j) {
      i64 other;
      swap(n[i], n[j]);
      sscanf(n,"%I64d",&other);
      if(other >= target && other<ans) {
        ans = other;
        break;
      }
      swap(n[i], n[j]);
    }
  }
  cout << ans << endl;
  return 0;
}

