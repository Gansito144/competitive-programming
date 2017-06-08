#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;


const int MaxN = 1234;
int sub[MaxN], L, R;

int main() {
  int N, M;
  
  scanf("%d",&N);
  for(int i=0; i<N; ++i) {
    scanf("%d",&sub[i]);
  }
  sort(sub, sub+N);
  for(int i=1; i<N; ++i) {
    sub[i] += sub[i-1];
  }
  scanf("%d",&M);
  int idx = 0, ans = 0;
  for(int i=0; i<M;++i) {
    scanf("%d %d",&L, &R);
    while(idx<N) {
      if(sub[idx]>R) break;
      L = max(sub[idx],L);
      ans = L;
      ++idx;
    }
  }
  if(idx != N) ans = -1;
  printf("%d\n",ans);
  return 0;
}

