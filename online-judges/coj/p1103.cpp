#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int i64;

const int maxValue = 748901;
const int coins[5] = {50, 25, 10, 5, 1};

i64 ways[maxValue];  

int main() {
  int n;
  ways[0] = 1LL;
  for(int c=0; c<5; ++c) {
    for(int val=1; val<maxValue; ++val) {
      if(val-coins[c] < 0) continue;
      ways[val] += ways[val-coins[c]];
    }
  }
  while(scanf("%d",&n) != EOF){
    printf("%lld\n",ways[n]);
  }
  return 0;
}

