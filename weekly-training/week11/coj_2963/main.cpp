#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int kMaxN = 1000006;
const int kInf  = 2e9;

bool prv[kMaxN], now[kMaxN];
int N;

int solve(bool ini, bool par) {
  int cnt = 0, n=N-1;
  memset(now, 0, sizeof now);
  now[0] = ini;
  for(int i=0; i<=N; ++i) {
    now[i] ^= prv[i];
    if(now[i] != par) {
      if(i==N) return kInf;
      ++cnt;
      now[i+0] ^= 1;
      now[i+1] ^= 1;
      now[i+2] ^= 1;
    }
  }
  return cnt;
}

int main() {
  int x, even=0, odds=0;
  
  scanf("%d",&N);
  for(int i=1; i<=N; ++i) {
    scanf("%d",&x);
    prv[i] = (x&1);
  }
  even = min(solve(0,0),solve(1,0));
  odds = min(solve(0,1),solve(1,1));
  if(even == kInf) even = -1;
  if(odds == kInf) odds = -1;
  printf("%d\n%d\n",odds, even);
  return 0;
}
