#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define i64 long long int
#define MAXN  100005
#define MAXM  1024
#define MAXP  10

const i64 primes[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int dp[2][MAXM];
char num_str[102];

int main () {
  i64 Xi, p;
  int n, mask, new_mask, prev, i, j, new, old;
  scanf("%s",num_str);
  n = atoi(num_str);
  for (i=1; i<=n; ++i) {
    scanf("%s",num_str);
    Xi = atoll(num_str);
    mask = 0;
    for (j=0; j<MAXP; ++j) {
      p = primes[j];
      new_mask = 1 << j;
      while (Xi % p == 0LL) {
        mask ^= new_mask;
        Xi /= p;
      }
    }
    new = i & 1;
    old = 1 - new;
    dp[new][mask] = 1;
    for (new_mask = 0; new_mask < MAXM; ++new_mask) {
      if (dp[old][new_mask])
        dp[new][new_mask] = dp[old][new_mask];
      prev = mask ^ new_mask;
      if (dp[old][prev] && dp[old][prev] >= dp[new][new_mask])
        dp[new][new_mask] = dp[old][prev] + 1;
    }
  }
  printf("%d\n",dp[n&1][0]);
  return 0;
}

