#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

const int MaxN = 1<<14;
int gauss[MaxN];

inline void sieve() {
  for(int i=1; i<MaxN; ++i) {
    gauss[i] = gauss[i-1] + i;
  }
}

int main() {
  int s, ans, sum;
  char buf[10];

  sieve();
  while(sscanf(gets(buf),"%d",&s), s) {
    ans = (1<<14)-1;
    for(int k=13; k>=0; --k) {
      ans ^= (gauss[ans^(1<<k)]>s) << k;
    }
    printf("%d %d\n", gauss[ans]-s, ans);
  }

  return 0;
}
